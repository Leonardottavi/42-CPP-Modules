/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:33:08 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/14 16:58:20 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Function to create a horde of zombies
Zombie* zombieHorde(int N, const std::string& name)
{
	if (N <= 0)
	{
		return NULL;
	}

	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		horde[i].setName(name);
	}
	return horde;
}
