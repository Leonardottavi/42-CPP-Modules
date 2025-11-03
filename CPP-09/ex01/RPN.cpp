/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:00:00 by lottavi           #+#    #+#             */
/*   Updated: 2025/11/03 09:12:16 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return *this;
}

bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isValidNumber(const std::string& token) const
{
	if (token.empty())
		return false;

	for (size_t i = 0; i < token.length(); i++)
	{
		if (!isdigit(token[i]))
			return false;
	}

	int num = std::atoi(token.c_str());
	return (num < 10);
}

bool RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isValidNumber(token))
		{
			int num = std::atoi(token.c_str());
			_stack.push(static_cast<double>(num));
		}
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return false;
			}

			double b = _stack.top();
			_stack.pop();
			double a = _stack.top();
			_stack.pop();

			double result;

			if (token == "+")
				result = a + b;
			else if (token == "-")
				result = a - b;
			else if (token == "*")
				result = a * b;
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error" << std::endl;
					return false;
				}
				result = a / b;
			}

			_stack.push(result);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return false;
		}
	}

	if (_stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return false;
	}

	return true;
}

double RPN::getResult() const
{
	if (_stack.empty())
		return 0;

	return _stack.top();
}
