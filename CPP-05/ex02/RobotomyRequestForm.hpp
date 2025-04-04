/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:14:18 by lottavi           #+#    #+#             */
/*   Updated: 2025/04/04 14:53:14 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class	RobotomyRequestForm : public AForm {
private:
	std::string	_target;

public:
	RobotomyRequestForm(const std::string& target);
	virtual ~RobotomyRequestForm();

protected:
	virtual void	executeAction() const;
};

#endif

