/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:32:57 by lottavi           #+#    #+#             */
/*   Updated: 2025/10/27 12:28:35 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main() {
	// Test from the subject
	std::cout << "=== Test from subject ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	// Test with too many numbers
	std::cout << "\n=== Test exception: too many numbers ===" << std::endl;
	{
		try {
			Span sp = Span(3);
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4); // Should throw
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	// Test with not enough numbers
	std::cout << "\n=== Test exception: not enough numbers ===" << std::endl;
	{
		try {
			Span sp = Span(5);
			sp.addNumber(1);
			std::cout << sp.shortestSpan() << std::endl; // Should throw
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	// Test with empty span
	std::cout << "\n=== Test exception: empty span ===" << std::endl;
	{
		try {
			Span sp = Span(5);
			std::cout << sp.longestSpan() << std::endl; // Should throw
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	// Test with 10,000 numbers
	std::cout << "\n=== Test with 10,000 numbers ===" << std::endl;
	{
		Span sp = Span(10000);
		std::srand(std::time(0));

		for (int i = 0; i < 10000; ++i) {
			sp.addNumber(std::rand());
		}

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	// Test with range of iterators
	std::cout << "\n=== Test with range of iterators ===" << std::endl;
	{
		Span sp = Span(10000);
		std::vector<int> vec;

		for (int i = 0; i < 10000; ++i) {
			vec.push_back(i * 2);
		}

		sp.addRange(vec.begin(), vec.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	// Test with negative numbers
	std::cout << "\n=== Test with negative numbers ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(-10);
		sp.addNumber(-5);
		sp.addNumber(0);
		sp.addNumber(5);
		sp.addNumber(10);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	// Test range exception
	std::cout << "\n=== Test range exception ===" << std::endl;
	{
		try {
			Span sp = Span(5);
			std::vector<int> vec;
			for (int i = 0; i < 10; ++i) {
				vec.push_back(i);
			}
			sp.addRange(vec.begin(), vec.end()); // Should throw after 5 elements
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	return 0;
}
