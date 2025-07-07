/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:32:22 by lottavi           #+#    #+#             */
/*   Updated: 2025/07/07 10:59:16 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor to initialize the name
Zombie::Zombie() : name("") {}

// Copy constructor
Zombie::Zombie(const Zombie& other) : name(other.name) {}

// Assignment operator
Zombie& Zombie::operator=(const Zombie& other)
{
	if (this != &other) {
		name = other.name;
	}
	return *this;
}

// Destructor to print a message when a zombie is destroyed
Zombie::~Zombie()
{
	std::cout << name << " is destroyed." << std::endl;
}

// Member function to announce the zombie
void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Function to set the name of the zombie
void Zombie::setName(const std::string& zombieName)
{
	name = zombieName;
}
