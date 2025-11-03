/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:00:00 by lottavi           #+#    #+#             */
/*   Updated: 2025/11/03 09:12:16 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

class RPN
{
	private:
		std::stack<double> _stack;

		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		bool isOperator(const std::string& token) const;
		bool isValidNumber(const std::string& token) const;

	public:
		RPN();
		~RPN();

		bool evaluate(const std::string& expression);
		double getResult() const;
};

#endif
