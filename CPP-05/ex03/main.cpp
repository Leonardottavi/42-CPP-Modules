/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:39:26 by lottavi           #+#    #+#             */
/*   Updated: 2025/04/04 14:57:39 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	Intern intern;
	Bureaucrat boss("CEO", 1);

	AForm* forms[4];
	forms[0] = intern.makeForm("shrubbery creation", "home");
	forms[1] = intern.makeForm("robotomy request", "Bender");
	forms[2] = intern.makeForm("presidential pardon", "Zaphod");
	forms[3] = intern.makeForm("fake form", "target");

	for (int i = 0; i < 4; i++) {
		if (forms[i]) {
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
			delete forms[i];
		}
	}
	return 0;
}
