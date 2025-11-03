/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:00:00 by lottavi           #+#    #+#             */
/*   Updated: 2025/11/03 09:12:17 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iomanip>
#include <cmath>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	RPN rpn;

	if (!rpn.evaluate(argv[1]))
		return 1;

	double result = rpn.getResult();

	// Handle floating point output
	if (result == static_cast<long>(result))
		std::cout << static_cast<long>(result) << std::endl;
	else
		std::cout << result << std::endl;

	return 0;
}
