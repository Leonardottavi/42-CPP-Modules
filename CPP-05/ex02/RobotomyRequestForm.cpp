/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:14:29 by lottavi           #+#    #+#             */
/*   Updated: 2025/03/12 19:14:29 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request", 72, 45), _target(target) {
	std::srand(std::time(0));
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!isSigned()) throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade()) throw AForm::GradeTooLowException();

	std::cout << "* Drilling noises *\n";
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!\n";
	else
		std::cout << "Robotomy failed for " << _target << "!\n";
}
