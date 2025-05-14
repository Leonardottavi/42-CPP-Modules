/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:20:48 by lottavi           #+#    #+#             */
/*   Updated: 2025/05/14 16:20:15 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main() {
	std::srand(std::time(NULL));

	Base*	obj1 = generate();
	std::cout << "Pointer: ";
	identify(obj1);
	std::cout << "Reference: ";
	identify(*obj1);
	delete obj1;

	Base*	obj2 = generate();
	std::cout << "Pointer: ";
	identify(obj2);
	std::cout << "Reference: ";
	identify(*obj2);
	delete obj2;

	return 0;
}

