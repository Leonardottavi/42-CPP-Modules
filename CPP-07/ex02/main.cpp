/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:14:56 by lottavi           #+#    #+#             */
/*   Updated: 2025/10/08 12:02:48 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void	testBasicFunctionality() {
	std::cout << "=== Testing Basic Functionality ===" << std::endl;

	// Test default constructor
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	// Test constructor with size
	Array<int> arr(5);
	std::cout << "Array with size 5 created, size: " << arr.size() << std::endl;

	// Test initialization (elements should be default-initialized)
	std::cout << "Default values: ";
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	// Test assignment
	for (size_t i = 0; i < arr.size(); i++) {
		arr[i] = i * 10;
	}

	std::cout << "After assignment: ";
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void	testCopyAndAssignment() {
	std::cout << "\n=== Testing Copy Constructor and Assignment ===" << std::endl;

	Array<int> original(3);
	original[0] = 10;
	original[1] = 20;
	original[2] = 30;

	// Test copy constructor
	Array<int> copy(original);
	std::cout << "Original: ";
	for (size_t i = 0; i < original.size(); i++) {
		std::cout << original[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Copy: ";
	for (size_t i = 0; i < copy.size(); i++) {
		std::cout << copy[i] << " ";
	}
	std::cout << std::endl;

	// Modify copy to ensure deep copy
	copy[0] = 999;
	std::cout << "After modifying copy[0] to 999:" << std::endl;
	std::cout << "Original[0]: " << original[0] << std::endl;
	std::cout << "Copy[0]: " << copy[0] << std::endl;

	// Test assignment operator
	Array<int> assigned;
	assigned = original;
	std::cout << "Assigned array: ";
	for (size_t i = 0; i < assigned.size(); i++) {
		std::cout << assigned[i] << " ";
	}
	std::cout << std::endl;
}

void	testBoundsChecking() {
	std::cout << "\n=== Testing Bounds Checking ===" << std::endl;

	Array<int> arr(3);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	// Test valid access
	std::cout << "Valid access arr[1]: " << arr[1] << std::endl;

	// Test negative index
	try {
		std::cout << "Trying to access arr[-1]..." << std::endl;
		arr[-1] = 0;
	} catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test out of bounds positive index
	try {
		std::cout << "Trying to access arr[3]..." << std::endl;
		arr[3] = 0;
	} catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void	testDifferentTypes() {
	std::cout << "\n=== Testing Different Types ===" << std::endl;

	// Test with strings
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";

	std::cout << "String array: ";
	for (size_t i = 0; i < strings.size(); i++) {
		std::cout << strings[i] << " ";
	}
	std::cout << std::endl;

	// Test with doubles
	Array<double> doubles(3);
	doubles[0] = 3.14;
	doubles[1] = 2.71;
	doubles[2] = 1.41;

	std::cout << "Double array: ";
	for (size_t i = 0; i < doubles.size(); i++) {
		std::cout << doubles[i] << " ";
	}
	std::cout << std::endl;
}

int	main(int, char**)
{
	testBasicFunctionality();
	testCopyAndAssignment();
	testBoundsChecking();
	testDifferentTypes();

    std::cout << "\n=== Original Test (Provided) ===" << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

	std::cout << "All tests passed!" << std::endl;
    return 0;
}
