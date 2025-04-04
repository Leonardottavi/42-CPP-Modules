/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:12:33 by lottavi           #+#    #+#             */
/*   Updated: 2025/04/04 14:51:36 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _signed;
	const int _requiredGradeToSign;
	const int _requiredGradeToExecute;

	AForm();

protected:
	virtual void executeAction() const = 0;

public:
	AForm(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string& getName() const;
	bool isSigned() const;
	int getRequiredGradeToSign() const;
	int getRequiredGradeToExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);
	void execute(const Bureaucrat& executor) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "AForm grade too high";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "AForm grade too low";
		}
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form is not signed";
		}
	};
};

#endif

