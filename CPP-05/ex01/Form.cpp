/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:02:20 by lottavi           #+#    #+#             */
/*   Updated: 2025/03/12 19:02:20 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Costruttore
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false),
	  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// Copia e assegnazione
Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {}

// Getters
const std::string& Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

// Metodi
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// Eccezioni
const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

// Operatore di output
std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form '" << form.getName()
	   << "' | Signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << " | Grade to sign: " << form.getGradeToSign()
	   << " | Grade to execute: " << form.getGradeToExecute();
	return os;
}
