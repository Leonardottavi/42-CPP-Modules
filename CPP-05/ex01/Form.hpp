/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:01:39 by lottavi           #+#    #+#             */
/*   Updated: 2025/04/04 14:27:09 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_signed;
	const int			_requiredGradeToSign;
	const int			_requiredGradeToExecute;

	Form();

public:
	Form(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	const std::string&	getName() const;
	bool				isSigned() const;
	int					getRequiredGradeToSign() const;
	int					getRequiredGradeToExecute() const;

	void				beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form grade too high";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form grade too low";
		}
	};
};

#endif
