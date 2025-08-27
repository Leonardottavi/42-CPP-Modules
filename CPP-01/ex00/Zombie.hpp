/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:16:46 by lottavi           #+#    #+#             */
/*   Updated: 2025/07/07 10:59:16 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
	std::string name;

public:
	// Default constructor
	Zombie();

	// Constructor to initialize the name
	Zombie(std::string zombieName);

	// Copy constructor
	Zombie(const Zombie& other);

	// Assignment operator
	Zombie& operator=(const Zombie& other);

	// Destructor to print a message when a zombie is destroyed
	~Zombie();

	// Member function to announce the zombie
	void announce();
};

#endif // ZOMBIE_HPP
