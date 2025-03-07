/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:32:11 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/14 17:02:32 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char** argv)
{
	(void)argc;
	int N = argv[1] ? atoi(argv[1]) : 0;
	std::string name = "HordeZombie";

	if(N == 0)
	{
		std::cerr << "Rick Grimes did it well, no more bridge!" << std::endl;
		return 1;
	}
	// Create a horde of zombies
	Zombie* horde = zombieHorde(N, name);

	// Ensure the horde was created successfully
	if (horde)
	{
		// Call announce() for each zombie in the horde
		for (int i = 0; i < N; ++i)
		{
			horde[i].announce();
		}
		// Delete the horde to avoid memory leaks
		delete[] horde;
	}
	else
	{
		std::cerr << "Failed to create zombie horde." << std::endl;
	}

	return 0;
}
