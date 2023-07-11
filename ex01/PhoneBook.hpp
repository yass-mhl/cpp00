/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:30:12 by ymehlil           #+#    #+#             */
/*   Updated: 2023/06/27 14:38:22 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook {
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        int get_nb_contact() const;
        int set_nb_contact();
        void increment_contact();
        void set_contact(int index, Contact contact);
        Contact get_contact(int index);

    private:
        int nb_contact;
        Contact contact[8];
};

#endif