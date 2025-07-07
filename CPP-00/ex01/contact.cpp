/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:02:40 by lottavi           #+#    #+#             */
/*   Updated: 2025/07/07 10:59:16 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
				 const std::string& phoneNumber, const std::string& darkestSecret)
	: firstName(firstName), lastName(lastName), nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

Contact::Contact(const Contact& other)
	: firstName(other.firstName), lastName(other.lastName), nickname(other.nickname), phoneNumber(other.phoneNumber), darkestSecret(other.darkestSecret) {}

Contact& Contact::operator=(const Contact& other) {
	if (this != &other) {
		firstName = other.firstName;
		lastName = other.lastName;
		nickname = other.nickname;
		phoneNumber = other.phoneNumber;
		darkestSecret = other.darkestSecret;
	}
	return *this;
}

Contact::~Contact() {}

std::string Contact::getFirstName() const {
	return firstName;
}

std::string Contact::getLastName() const {
	return lastName;
}

std::string Contact::getNickname() const {
	return nickname;
}

std::string Contact::getPhoneNumber() const {
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return darkestSecret;
}
