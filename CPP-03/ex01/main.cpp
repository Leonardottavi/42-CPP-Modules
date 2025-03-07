/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:42:54 by lottavi           #+#    #+#             */
/*   Updated: 2025/01/17 15:08:54 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap scav("Scavvy");
	scav.attack("target");
	int damage, repair;
	std::cout << "\033[34mEnter damage value:\033[0m ";
	std::cin >> damage;
	scav.takeDamage(damage);
	std::cout << "\033[34mEnter repair value:\033[0m ";
	std::cin >> repair;
	scav.beRepaired(repair);
	scav.guardGate();
	return 0;
}
