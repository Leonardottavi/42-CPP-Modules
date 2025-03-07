/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:10:35 by lottavi           #+#    #+#             */
/*   Updated: 2025/01/17 14:45:32 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	claptrap("Robot");

	int	damage, repair;

	while (true)
	{
		std::cout << "\033[34mEnter damage for attack: \033[0m";
		std::cin >> damage;
		std::cout << "\033[34mEnter repair amount: \033[0m";
		std::cin >> repair;

		claptrap.attack("target");
		claptrap.takeDamage(damage);
		claptrap.beRepaired(repair);

		if (claptrap.getHitPoints() <= 0)
		{
			std::cout << "ClapTrap is destroyed!" << std::endl;
			break;
		}
	}

	return 0;
}
