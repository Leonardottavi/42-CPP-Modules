/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:13:50 by lottavi           #+#    #+#             */
/*   Updated: 2025/04/04 14:53:39 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class	ShrubberyCreationForm : public AForm {
private:
	std::string	_target;

public:
	ShrubberyCreationForm(const std::string& target);
	virtual ~ShrubberyCreationForm();

protected:
	virtual void	executeAction() const;
};

#endif

