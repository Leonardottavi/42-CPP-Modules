/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:19:57 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/20 14:31:53 by lottavi          ###   ########.fr       */
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
