/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:13:35 by lottavi           #+#    #+#             */
/*   Updated: 2025/04/04 14:51:12 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade)
	: _name(name), _signed(false), _requiredGradeToSign(signGrade), _requiredGradeToExecute(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed),
	  _requiredGradeToSign(other._requiredGradeToSign),
	  _requiredGradeToExecute(other._requiredGradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		_signed = other._signed;
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getRequiredGradeToSign() const { return _requiredGradeToSign; }
int AForm::getRequiredGradeToExecute() const { return _requiredGradeToExecute; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _requiredGradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat& executor) const {
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _requiredGradeToExecute)
		throw GradeTooLowException();
	executeAction();
}
