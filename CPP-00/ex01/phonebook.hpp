/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:03:22 by lottavi           #+#    #+#             */
/*   Updated: 2025/07/07 10:59:16 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "contact.hpp"

class Phonebook
{
private:
	Contact contacts[8];
	int contactCount;
	int nextIndex;

public:
	Phonebook();
	Phonebook(const Phonebook& other);
	Phonebook& operator=(const Phonebook& other);
	~Phonebook();

	void addContact(const Contact& contact);
	void searchContact() const;
	void viewContact(int index) const;
	int getContactCount() const;
};

#endif // PHONEBOOK_HPP
