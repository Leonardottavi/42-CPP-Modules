/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:32:22 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/14 16:58:11 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor to initialize the name
Zombie::Zombie() : name("") {}

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
