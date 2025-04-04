/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:15:10 by lottavi           #+#    #+#             */
/*   Updated: 2025/04/04 14:52:25 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main() {
	try {
		Bureaucrat	ceo("Zaphod", 1);
		Bureaucrat	intern("Bob", 150);

		ShrubberyCreationForm	shrub("home");
		RobotomyRequestForm		robotomy("Marvin");
		PresidentialPardonForm	pardon("Arthur");

		ceo.signForm(shrub);
		ceo.signForm(robotomy);
		ceo.signForm(pardon);

		ceo.executeForm(shrub);
		ceo.executeForm(robotomy);
		ceo.executeForm(pardon);

		intern.executeForm(pardon); // Should fail due to low grade

		// Test unsigned form
		PresidentialPardonForm	unsignedPardon("Ford");
		ceo.executeForm(unsignedPardon); // Should throw FormNotSignedException

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
