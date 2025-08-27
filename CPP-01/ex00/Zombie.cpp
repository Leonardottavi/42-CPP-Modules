/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:19:57 by lottavi           #+#    #+#             */
/*   Updated: 2025/07/07 10:59:16 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie() : name("Unnamed Zombie")
{
	std::cout << "A zombie has been created with the default constructor." << std::endl;
}

// Constructor to initialize the name
Zombie::Zombie(std::string zombieName) : name(zombieName)
{
	std::cout << "A zombie named " << name << " has been created." << std::endl;
}

// Copy constructor
Zombie::Zombie(const Zombie& other) : name(other.name)
{
	std::cout << "A zombie named " << name << " has been created by copy." << std::endl;
}

// Assignment operator
Zombie& Zombie::operator=(const Zombie& other)
{
	if (this != &other) {
		name = other.name;
		std::cout << "A zombie has been assigned the name " << name << std::endl;
	}
	return *this;
}

// Destructor
Zombie::~Zombie()
{
	std::cout << "A zombie named " << name << " has been destroyed." << std::endl;
}

// Member function to announce the zombie
void Zombie::announce()
{
	std::cout << name << " is announcing: Braiiiiiiinnnssss..." << std::endl;
}
