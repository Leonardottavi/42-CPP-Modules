/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:05:00 by lottavi           #+#    #+#             */
/*   Updated: 2025/11/03 09:12:44 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <utility>

class PmergeMe
{
	private:
		std::vector<int> _vectorData;
		std::deque<int> _dequeData;

		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		// Vector sorting
		void mergeInsertSortVector(std::vector<int>& arr, int left, int right);
		void mergeVector(std::vector<int>& arr, int left, int mid, int right);
		void binaryInsertVector(std::vector<int>& arr, int pos);

		// Deque sorting
		void mergeInsertSortDeque(std::deque<int>& arr, int left, int right);
		void mergeDeque(std::deque<int>& arr, int left, int mid, int right);
		void binaryInsertDeque(std::deque<int>& arr, int pos);

	public:
		PmergeMe();
		~PmergeMe();

		bool parseInput(int argc, char** argv);
		void sortVector();
		void sortDeque();

		void displayBefore() const;
		void displayAfter() const;
		double getVectorTime() const;
		double getDequeTime() const;

		std::vector<int> getVectorData() const;
		std::deque<int> getDequeData() const;
};

#endif
