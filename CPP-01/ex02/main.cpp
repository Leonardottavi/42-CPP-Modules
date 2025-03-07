/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:04:55 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/14 17:11:39 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
	// Initialize a string variable
	std::string brain = "HI THIS IS BRAIN";

	// Create a pointer to the string
	std::string* stringPTR = &brain;

	// Create a reference to the string
	std::string& stringREF = brain;

	// Print the memory address of the string variable
	std::cout << "Memory address of the string variable: " << &brain << std::endl;

	// Print the memory address held by stringPTR
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;

	// Print the memory address held by stringREF
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	// Print the value of the string variable
	std::cout << "Value of the string variable: " << brain << std::endl;

	// Print the value pointed to by stringPTR
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;

	// Print the value pointed to by stringREF
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	return 0;
}
