/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:14:39 by lottavi           #+#    #+#             */
/*   Updated: 2025/04/04 14:52:48 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		PresidentialPardonForm(const std::string& target);
		virtual ~PresidentialPardonForm();

	protected:
		virtual void executeAction() const;
};

#endif
