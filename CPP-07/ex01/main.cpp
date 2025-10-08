/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:12:57 by lottavi           #+#    #+#             */
/*   Updated: 2025/10/08 12:00:26 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void print(T const& x) {
	std::cout << x << " ";
}

template<typename T>
void increment(T& x) {
	x++;
}

void toUpper(char& c) {
	if (c >= 'a' && c <= 'z') {
		c = c - 'a' + 'A';
	}
}

int main(void) {
	std::cout << "=== Testing with integers ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original array: ";
	::iter(intArray, intSize, print<int>);
	std::cout << std::endl;

	::iter(intArray, intSize, increment<int>);
	std::cout << "After increment: ";
	::iter(intArray, intSize, print<int>);
	std::cout << std::endl;

	std::cout << "\n=== Testing with doubles ===" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Double array: ";
	::iter(doubleArray, doubleSize, print<double>);
	std::cout << std::endl;

	std::cout << "\n=== Testing with strings ===" << std::endl;
	std::string stringArray[] = {"hello", "world", "from", "templates"};
	size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

	std::cout << "String array: ";
	::iter(stringArray, stringSize, print<std::string>);
	std::cout << std::endl;

	std::cout << "\n=== Testing with chars ===" << std::endl;
	char charArray[] = {'h', 'e', 'l', 'l', 'o'};
	size_t charSize = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << "Original chars: ";
	::iter(charArray, charSize, print<char>);
	std::cout << std::endl;

	::iter(charArray, charSize, toUpper);
	std::cout << "After toUpper: ";
	::iter(charArray, charSize, print<char>);
	std::cout << std::endl;

	return 0;
}
