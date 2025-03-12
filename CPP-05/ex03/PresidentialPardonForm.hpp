/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:14:39 by lottavi           #+#    #+#             */
/*   Updated: 2025/03/12 19:14:39 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string _target;

public:
	static AForm* create(const std::string& target) {
		return new PresidentialPardonForm(target);
	}
	PresidentialPardonForm(const std::string& target);
	virtual void execute(const Bureaucrat& executor) const;
};

#endif
