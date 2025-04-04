/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:14:29 by lottavi           #+#    #+#             */
/*   Updated: 2025/04/04 14:53:04 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
	std::cout << "Drilling noises... Brrrrr!\n";
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!\n";
	else
		std::cout << "Robotomy on " << _target << " failed.\n";
}
