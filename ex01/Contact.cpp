/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:36:23 by ymehlil           #+#    #+#             */
/*   Updated: 2023/07/12 15:15:45 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
    return ;
}

Contact::~Contact(void) {
    return ;
}

std::string Contact::get_info(std::string info) const {
    if (info == "first_name")
        return this->first_name;
    else if (info == "last_name")
        return this->last_name;
    else if (info == "nickname")
        return this->nickname;
    else if (info == "phone_number")
        return this->phone_number;
    else if (info == "darkest_secret")
        return this->darkest_secret;
    return NULL;
}

void Contact::set_info(std::string info, std::string str) {
    if (info == "first_name")
        this->first_name = str;
    else if (info == "last_name")
        this->last_name = str;
    else if (info == "nickname")
        this->nickname = str;    
    else if (info == "phone_number")
        this->phone_number = str;
    else if (info == "darkest_secret")
        this->darkest_secret = str;
}
