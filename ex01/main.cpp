/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:30:05 by ymehlil           #+#    #+#             */
/*   Updated: 2023/06/27 15:33:41 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int add_contact(PhoneBook& phonebook)
{
    Contact contact;
    std::string input;
    // First name
    std::cout << "Please enter the first name : " << std::endl;
    std::getline(std::cin, input);
    while (input == "")
        std::getline(std::cin, input);
    contact.set_info("first_name", input);    
    // Last Name
    std::cout << "Please enter the last name : " << std::endl;
    std::getline(std::cin, input);
    while (input == "")
        std::getline(std::cin, input);
    contact.set_info("last_name", input);
    // Nickname
    std::cout << "Please enter the nickname: " << std::endl;
    std::getline(std::cin, input);
    while (input == "")
        std::getline(std::cin, input);
    contact.set_info("nickname", input);
    // Phone Number
    std::cout << "Please enter the phone number : " << std::endl;
    std::getline(std::cin, input);
    while (input == "")
        std::getline(std::cin, input);
    contact.set_info("phone_number", input);
    // Darkest secret
    std::cout << "Please enter the darkest secret : " << std::endl;
    std::getline(std::cin, input);
    while (input == "")
        std::getline(std::cin, input);
    contact.set_info("darkest_secret", input);
    
    // Add in phonebook
    if (phonebook.get_nb_contact() <= 8)
    {
        std::cout << phonebook.get_nb_contact() << std::endl;
        phonebook.set_contact(phonebook.get_nb_contact(), contact);
    }
    else
        phonebook.set_contact(0, contact);
    return (1);
}

int main(void) {
    PhoneBook phonebook;

    add_contact(phonebook);
    std::cout << "Le nom de l'utilisteur 0 est " + phonebook.get_contact(0).get_info("first_name") << std::endl;
    
}