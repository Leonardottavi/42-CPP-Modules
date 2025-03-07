/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:20:09 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/14 15:51:59 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "NewZombie.hpp"
#include "RandomChump.hpp"

int main() {
	// Example usage of newZombie
	Zombie* z1 = NewZombie("Zombie1");
	z1->announce();
	delete z1; // Don't forget to delete the allocated memory

	// Example usage of randomChump
	RandomChump("Zombie2");

	return 0;
}
