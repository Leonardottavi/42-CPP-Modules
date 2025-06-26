/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:14:56 by lottavi           #+#    #+#             */
/*   Updated: 2025/06/26 16:14:56 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

#define MAX_VAL 750

int main(int, char**) {
	// Test default constructor
	std::cout << "=== Testing default constructor ===" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	// Test constructor with size
	std::cout << "\n=== Testing constructor with size ===" << std::endl;
	Array<int> numbers(MAX_VAL);
	Array<int> mirror(MAX_VAL);

	std::cout << "Array size: " << numbers.size() << std::endl;

	// Fill arrays
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand() % 100;
		numbers[i] = value;
		mirror[i] = value;
	}

	// Test copy constructor
	std::cout << "\n=== Testing copy constructor ===" << std::endl;
	Array<int> tmp = numbers;
	Array<int> test(numbers);
	std::cout << "Copy created successfully" << std::endl;

	// Test that modifying copy doesn't affect original
	std::cout << "\n=== Testing deep copy ===" << std::endl;
	std::cout << "Original numbers[0]: " << numbers[0] << std::endl;
	std::cout << "Copy tmp[0]: " << tmp[0] << std::endl;
	tmp[0] = 999;
	std::cout << "After modifying copy:" << std::endl;
	std::cout << "Original numbers[0]: " << numbers[0] << std::endl;
	std::cout << "Modified tmp[0]: " << tmp[0] << std::endl;

	// Test bounds checking
	std::cout << "\n=== Testing bounds checking ===" << std::endl;
	try {
		numbers[-2] = 0; // This should throw
	} catch(const std::exception& e) {
		std::cout << "Caught expected exception for negative index: " << e.what() << std::endl;
	}

	try {
		numbers[MAX_VAL] = 0; // This should throw
	} catch(const std::exception& e) {
		std::cout << "Caught expected exception for out of bounds: " << e.what() << std::endl;
	}

	// Test with different types
	std::cout << "\n=== Testing with different types ===" << std::endl;

	// String array
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";

	std::cout << "String array: ";
	for (size_t i = 0; i < strings.size(); i++) {
		std::cout << strings[i] << " ";
	}
	std::cout << std::endl;

	// Float array
	Array<float> floats(5);
	for (size_t i = 0; i < floats.size(); i++) {
		floats[i] = i * 1.5f;
	}

	std::cout << "Float array: ";
	for (size_t i = 0; i < floats.size(); i++) {
		std::cout << floats[i] << " ";
	}
	std::cout << std::endl;

	// Test assignment operator
	std::cout << "\n=== Testing assignment operator ===" << std::endl;
	Array<float> floats2;
	floats2 = floats;
	std::cout << "Assignment completed. New array size: " << floats2.size() << std::endl;

	// Verify deep copy with assignment
	floats2[0] = 999.9f;
	std::cout << "Original floats[0]: " << floats[0] << std::endl;
	std::cout << "Assigned floats2[0]: " << floats2[0] << std::endl;

	return 0;
}
