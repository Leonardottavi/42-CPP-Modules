/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:14:08 by lottavi           #+#    #+#             */
/*   Updated: 2025/04/04 14:53:28 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
	std::ofstream file((_target + "_shrubbery").c_str());
	if (file.is_open()) {
		file << "       _-_\n"
				"    /~~   ~~\\\n"
				" /~~         ~~\\\n"
				"{               }\n"
				" \\  _-     -_  /\n"
				"   ~  \\\\ //  ~\n"
				"_- -   | | _- _\n"
				"  _ -  | |   -_\n"
				"      // \\\\\n";
		file.close();
	}
}
