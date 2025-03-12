/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:13:35 by lottavi           #+#    #+#             */
/*   Updated: 2025/03/12 19:13:35 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade)
	: _name(name), _isSigned(false),
	  _gradeToSign(signGrade), _gradeToExecute(execGrade) {
	if (signGrade < 1 || execGrade < 1) throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) _isSigned = other._isSigned;
	return *this;
}

const std::string& AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getSignGrade() const { return _gradeToSign; }
int AForm::getExecGrade() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign) throw GradeTooLowException();
	_isSigned = true;
}

// Eccezioni
const char* AForm::GradeTooHighException::what() const throw() { return "Grade too high!"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Grade too low!"; }
const char* AForm::FormNotSignedException::what() const throw() { return "Form not signed!"; }

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form '" << form.getName()
	   << "' | Signed: " << (form.isSigned() ? "Yes" : "No")
	   << " | Sign Grade: " << form.getSignGrade()
	   << " | Exec Grade: " << form.getExecGrade();
	return os;
}
