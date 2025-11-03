/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:05:00 by lottavi           #+#    #+#             */
/*   Updated: 2025/11/03 09:12:17 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe sorter;

	if (!sorter.parseInput(argc, argv))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	sorter.displayBefore();

	sorter.sortVector();
	sorter.sortDeque();

	sorter.displayAfter();

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << sorter.getVectorData().size()
	          << " elements with std::vector : " << sorter.getVectorTime() << " us" << std::endl;
	std::cout << "Time to process a range of " << sorter.getDequeData().size()
	          << " elements with std::deque : " << sorter.getDequeTime() << " us" << std::endl;

	return 0;
}
