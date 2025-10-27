/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:11:16 by lottavi           #+#    #+#             */
/*   Updated: 2025/10/27 10:11:22 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	// Test with vector
	std::cout << "=== Testing with std::vector ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 10);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test with list
	std::cout << "\n=== Testing with std::list ===" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	try {
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(lst, 100);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test with deque
	std::cout << "\n=== Testing with std::deque ===" << std::endl;
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	try {
		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::deque<int>::iterator it = easyfind(deq, 400);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test with empty container
	std::cout << "\n=== Testing with empty container ===" << std::endl;
	std::vector<int> empty;
	try {
		std::vector<int>::iterator it = easyfind(empty, 1);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
