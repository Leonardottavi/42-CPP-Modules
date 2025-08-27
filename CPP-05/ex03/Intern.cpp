/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:25:38 by lottavi           #+#    #+#             */
/*   Updated: 2025/07/07 10:59:16 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const Intern::FormCreator Intern::_formCreators[3] = {
    {"shrubbery creation", ShrubberyCreationForm::create},
    {"robotomy request", RobotomyRequestForm::create},
    {"presidential pardon", PresidentialPardonForm::create}
};

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    for (int i = 0; i < 3; i++) {
        if (_formCreators[i].formName == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return _formCreators[i].createFunc(target);
        }
    }
    std::cout << "Error: Form '" << formName << "' doesn't exist!" << std::endl;
    return NULL;
}
