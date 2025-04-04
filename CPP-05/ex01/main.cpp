/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:59:07 by lottavi           #+#    #+#             */
/*   Updated: 2025/04/04 14:27:24 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat high("Alice", 1);
		Bureaucrat low("Bob", 150);

		Form form1("Tax Form", 50, 50);
		Form form2("Secret Form", 10, 10);

		high.signForm(form1);	// Should succeed
		low.signForm(form2);	// Should fail

		Form form3("Top Secret", 5, 5);
		low.signForm(form3);	// Should fail

		Bureaucrat medium("Charlie", 10);
		Form form4("Medium Form", 10, 10);
		medium.signForm(form4);	// Should succeed

		std::cout << form1.getName() << " signed status: " << form1.isSigned() << std::endl;
		std::cout << form2.getName() << " signed status: " << form2.isSigned() << std::endl;
		std::cout << form4.getName() << " signed status: " << form4.isSigned() << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
