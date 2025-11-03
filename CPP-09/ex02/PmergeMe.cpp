/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:05:00 by lottavi           #+#    #+#             */
/*   Updated: 2025/11/03 09:12:51 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>
#include <sys/time.h>
#include <cmath>

static double _vectorTime = 0;
static double _dequeTime = 0;

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vectorData = other._vectorData;
		_dequeData = other._dequeData;
	}
	return *this;
}

bool PmergeMe::parseInput(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		char* endptr;
		long num = strtol(argv[i], &endptr, 10);

		if (*endptr != '\0' || num < 0 || num > 2147483647)
			return false;

		_vectorData.push_back(static_cast<int>(num));
		_dequeData.push_back(static_cast<int>(num));
	}

	return !_vectorData.empty();
}

void PmergeMe::binaryInsertVector(std::vector<int>& arr, int pos)
{
	int key = arr[pos];
	int left = 0;
	int right = pos - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}

	for (int i = pos; i > left; i--)
		arr[i] = arr[i - 1];

	arr[left] = key;
}

void PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right)
{
	std::vector<int> temp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while (i <= mid)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];

	for (i = left, k = 0; i <= right; i++, k++)
		arr[i] = temp[k];
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeInsertSortVector(arr, left, mid);
		mergeInsertSortVector(arr, mid + 1, right);

		// Binary insertion for small subarrays
		if (right - left < 10)
		{
			for (int i = left + 1; i <= right; i++)
				binaryInsertVector(arr, i);
		}
		else
		{
			mergeVector(arr, left, mid, right);
		}
	}
}

void PmergeMe::binaryInsertDeque(std::deque<int>& arr, int pos)
{
	int key = arr[pos];
	int left = 0;
	int right = pos - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}

	for (int i = pos; i > left; i--)
		arr[i] = arr[i - 1];

	arr[left] = key;
}

void PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right)
{
	std::deque<int> temp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while (i <= mid)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];

	for (i = left, k = 0; i <= right; i++, k++)
		arr[i] = temp[k];
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeInsertSortDeque(arr, left, mid);
		mergeInsertSortDeque(arr, mid + 1, right);

		// Binary insertion for small subarrays
		if (right - left < 10)
		{
			for (int i = left + 1; i <= right; i++)
				binaryInsertDeque(arr, i);
		}
		else
		{
			mergeDeque(arr, left, mid, right);
		}
	}
}

void PmergeMe::sortVector()
{
	clock_t start = clock();
	mergeInsertSortVector(_vectorData, 0, _vectorData.size() - 1);
	clock_t end = clock();
	_vectorTime = (end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

void PmergeMe::sortDeque()
{
	clock_t start = clock();
	mergeInsertSortDeque(_dequeData, 0, _dequeData.size() - 1);
	clock_t end = clock();
	_dequeTime = (end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

void PmergeMe::displayBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vectorData.size(); i++)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << _vectorData[i];
	}
	std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
	std::cout << "After: ";
	for (size_t i = 0; i < _vectorData.size(); i++)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << _vectorData[i];
	}
	std::cout << std::endl;
}

double PmergeMe::getVectorTime() const
{
	return _vectorTime;
}

double PmergeMe::getDequeTime() const
{
	return _dequeTime;
}

std::vector<int> PmergeMe::getVectorData() const
{
	return _vectorData;
}

std::deque<int> PmergeMe::getDequeData() const
{
	return _dequeData;
}
