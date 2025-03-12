/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:59:07 by lottavi           #+#    #+#             */
/*   Updated: 2025/03/12 18:59:07 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat high("Alice", 1);
		Bureaucrat low("Bob", 150);
		Form form("Tax Return", 50, 50);

		std::cout << "\n--- Test firma valida ---\n";
		high.signForm(form);
		std::cout << form << std::endl;

		std::cout << "\n--- Test firma non valida ---\n";
		low.signForm(form);

		std::cout << "\n--- Test creazione form non valido ---\n";
		Form invalid("Invalid", 0, 151); // Dovrebbe lanciare eccezione
	}
	catch (const std::exception& e) {
		std::cerr << "\nError: " << e.what() << std::endl;
	}
	return 0;
}
