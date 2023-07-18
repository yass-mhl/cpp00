/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:30:05 by ymehlil           #+#    #+#             */
/*   Updated: 2023/07/18 12:59:40 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

void	swipe_contact(PhoneBook& phonebook, Contact& contact)
{
	for (int i = 0; i < 7; ++i) {
        Contact next_contact = phonebook.get_contact(i + 1);
        phonebook.set_contact(i, next_contact); 
    }
    phonebook.set_contact(7, contact);
}
// Function to add a contact in the phonebook

int	add_contact(PhoneBook &phonebook)
{
	Contact	contact;

	std::string input;
	// Ask for the information
	// First Name
	
	std::cout << "Please enter the first name : " << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof())
		return (-1);
	while (input == "")
		std::getline(std::cin, input);
	contact.set_info("first_name", input);
	
	// Last Name
	std::cout << "Please enter the last name : " << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof())
		return (-1);
	while (input == "")
		std::getline(std::cin, input);
	contact.set_info("last_name", input);

	// Nickname
	std::cout << "Please enter the nickname: " << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof())
		return (-1);
	while (input == "")
		std::getline(std::cin, input);
	contact.set_info("nickname", input);

	// Phone Number
	std::cout << "Please enter the phone number : " << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof())
		return (-1);
	while (input == "")
		std::getline(std::cin, input);
	contact.set_info("phone_number", input);

	// Darkest secret
	std::cout << "Please enter the darkest secret : " << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof())
		return (-1);
	while (input == "")
		std::getline(std::cin, input);
	contact.set_info("darkest_secret", input);

	// Add in phonebook
	if (phonebook.get_nb_contact() < 8)
	{
		phonebook.set_contact(phonebook.get_nb_contact(), contact);
		phonebook.increment_contact();
	}
	else
		swipe_contact(phonebook, contact);
	return (1);
}


void print_box(std::string str, int len)
{
	int i;

	i = 0;
	while (i < 10 - len)
	{
		std::cout << " ";
		i++;
	}
	std::cout << str << "|";
}

// Function to search a contact in the phonebook
int search_contact(PhoneBook& phonebook)
{
	int i;
	int index;
	std::string input;

	i = 0;
	if (phonebook.get_nb_contact() == 0)
	{
		std::cout << "No contact in the phonebook" << std::endl;
		return (0);
	}
	else
	{
		std::cout << "     index|first name| last name|  nickname" << std::endl;
		while (i < phonebook.get_nb_contact())
		{
			std::cout << "         " << i << "|";
			if (phonebook.get_contact(i).get_info("first_name").length() > 10)
				std::cout << phonebook.get_contact(i).get_info("first_name").substr(0, 9) << ".|";
			else
				print_box(phonebook.get_contact(i).get_info("first_name"), phonebook.get_contact(i).get_info("first_name").length());
			if (phonebook.get_contact(i).get_info("last_name").length() > 10)
				std::cout << phonebook.get_contact(i).get_info("last_name").substr(0, 9) << ".|";
			else
				print_box(phonebook.get_contact(i).get_info("last_name"), phonebook.get_contact(i).get_info("last_name").length());
			if (phonebook.get_contact(i).get_info("nickname").length() > 10)
				std::cout << phonebook.get_contact(i).get_info("nickname").substr(0, 9) << ".|";
			else
				print_box(phonebook.get_contact(i).get_info("nickname"), phonebook.get_contact(i).get_info("nickname").length());
			std::cout << std::endl;
			i++;
		}
		std::cout << "Please enter the index of the contact you want to see : " << std::endl;
		std::cin >> index;
		if (std::cin.eof())
			return (-1);
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Invalid index" << std::endl;
			return (0);
		}
		else if (index < 0 || index >= phonebook.get_nb_contact())
		{
			std::cout << "Invalid index" << std::endl;
			return (0);
		}
		std::cout << "First name : " << phonebook.get_contact(index).get_info("first_name") << std::endl;
		std::cout << "Last name : " << phonebook.get_contact(index).get_info("last_name") << std::endl;
		std::cout << "Nickname : " << phonebook.get_contact(index).get_info("nickname") << std::endl;
		std::cout << "Phone number : " << phonebook.get_contact(index).get_info("phone_number") << std::endl;
		std::cout << "Darkest secret : " << phonebook.get_contact(index).get_info("darkest_secret") << std::endl;
	}
	return (1);
	
}

static void print_menu(void)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Please enter a command : " << std::endl;
	std::cout << "ADD : Add a contact" << std::endl;
	std::cout << "SEARCH : Search a contact" << std::endl;
	std::cout << "EXIT : Exit the program" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	
}

static int menu(PhoneBook& phonebook)
{
	std::string input;
	
	print_menu();
	std::getline(std::cin, input);
	if (std::cin.eof())
		return (std::cout << "Bye !" << std::endl, -1);
	while (input == "")
		std::getline(std::cin, input);
	if (input == "ADD")
		add_contact(phonebook);
	else if (input == "SEARCH")
	{
		if (search_contact(phonebook) == -1)
			return (std::cout << "Bye !" << std::endl, -1);
	}
	else if (input == "EXIT")
		return (std::cout << "Bye !" << std::endl, -1);
	else
		std::cout << "Invalid command" << std::endl;
	menu(phonebook);
	return (0);
}

int	main(void)
{
	PhoneBook phonebook;

	std::cout << "Welcome to the phonebook !" << std::endl;
	if (menu(phonebook) == -1)
		return (0);
}
