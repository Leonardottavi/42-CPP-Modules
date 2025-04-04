/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:02:20 by lottavi           #+#    #+#             */
/*   Updated: 2025/04/04 14:26:47 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute)
	: _name(name), _signed(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute) {
	if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
		throw GradeTooHighException();
	if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed), _requiredGradeToSign(other._requiredGradeToSign), _requiredGradeToExecute(other._requiredGradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const { return _name; }
bool Form::isSigned() const { return _signed; }
int Form::getRequiredGradeToSign() const { return _requiredGradeToSign; }
int Form::getRequiredGradeToExecute() const { return _requiredGradeToExecute; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _requiredGradeToSign)
		throw GradeTooLowException();
	_signed = true;
}
