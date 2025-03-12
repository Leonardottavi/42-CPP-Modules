/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:56:35 by lottavi           #+#    #+#             */
/*   Updated: 2025/03/12 18:56:35 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Costruttore e validazione iniziale
Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade) {
	validateGrade();
}

void Bureaucrat::validateGrade() const {
	if (_grade < 1) throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {}

// Assegnazione
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

// Getters
const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

// Modifica del grado
void Bureaucrat::incrementGrade() {
	_grade--;
	validateGrade();
}

void Bureaucrat::decrementGrade() {
	_grade++;
	validateGrade();
}

// Interazione con i form
void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << _name << " failed to execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

// Implementazioni eccezioni
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high (max 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low (min 150)";
}

// Operatore di output
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
