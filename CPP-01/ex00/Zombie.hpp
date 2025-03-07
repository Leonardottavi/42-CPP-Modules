/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:16:46 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/20 14:31:06 by lottavi          ###   ########.fr       */
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

	// Destructor to print a message when a zombie is destroyed
	~Zombie();

	// Member function to announce the zombie
	void announce();
};

#endif // ZOMBIE_HPP
