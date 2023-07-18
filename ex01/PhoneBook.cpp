/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:05:14 by ymehlil           #+#    #+#             */
/*   Updated: 2023/07/11 10:53:55 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    this->nb_contact = 0;
    return ;
}

PhoneBook::~PhoneBook(void) {
    return ;
}

int PhoneBook::get_nb_contact(void) const {
    return (this->nb_contact);
}

void PhoneBook::increment_contact(void) {
    this->nb_contact++;
}

void PhoneBook::set_contact(int index, Contact contact)
{
    this->contact[index] = contact;
}

Contact PhoneBook::get_contact(int index)
{
    return (this->contact[index]);
}
