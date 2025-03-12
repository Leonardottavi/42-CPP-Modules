/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:12:33 by lottavi           #+#    #+#             */
/*   Updated: 2025/03/12 19:12:33 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
protected:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

	AForm();

public:
	AForm(const std::string& name, int signGrade, int execGrade);
	AForm(const AForm& other);
	virtual ~AForm();
	AForm& operator=(const AForm& other);

	const std::string&	getName() const;
	bool				isSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	void				beSigned(const Bureaucrat& bureaucrat);
	virtual void		execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
		public: const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public: const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
		public: const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
