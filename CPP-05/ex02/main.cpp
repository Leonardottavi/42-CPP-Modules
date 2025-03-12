/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:15:10 by lottavi           #+#    #+#             */
/*   Updated: 2025/03/12 19:15:10 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat ceo("CEO", 1);
	Bureaucrat intern("Intern", 150);

	ShrubberyCreationForm shrub("Garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Ford");

	ceo.signForm(shrub);
	ceo.signForm(robot);
	ceo.signForm(pardon);

	std::cout << "\n--- Execute Forms ---\n";
	ceo.executeForm(shrub);   // Successo
	ceo.executeForm(robot);   // 50% chance
	ceo.executeForm(pardon);  // Successo

	std::cout << "\n--- Test Errori ---\n";
	intern.executeForm(pardon); // Grado troppo basso
	PresidentialPardonForm invalidPardon("Zaphod");
	ceo.executeForm(invalidPardon); // Form non firmato

	return 0;
}
