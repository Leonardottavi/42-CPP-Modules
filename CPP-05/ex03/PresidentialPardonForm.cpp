/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*   Created: 2025/03/12 19:14:48 by lottavi           #+#    #+#             */
/*   Updated: 2025/03/12 19:14:48 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!isSigned()) throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade()) throw AForm::GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!\n";
}
