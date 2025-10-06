/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:00:00 by lottavi           #+#    #+#             */
/*   Updated: 2025/10/06 11:42:45 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
class Array {
private:
	T* _array;
	size_t _size;

public:
	// Default constructor - creates empty array
	Array() : _array(NULL), _size(0) {}

	// Constructor with size parameter
	Array(unsigned int n) : _array(new T[n]()), _size(n) {}

	// Copy constructor
	Array(Array const& other) : _array(NULL), _size(0) {
		*this = other;
	}

	// Assignment operator
	Array& operator=(Array const& other) {
		if (this != &other) {
			delete[] _array;
			_size = other._size;
			if (_size > 0) {
				_array = new T[_size];
				for (size_t i = 0; i < _size; i++) {
					_array[i] = other._array[i];
				}
			} else {
				_array = NULL;
			}
		}
		return *this;
	}

	// Destructor
	~Array() {
		delete[] _array;
	}

	// Subscript operator with bounds checking
	T& operator[](int index) {
		if (index < 0 || static_cast<size_t>(index) >= _size) {
			throw std::out_of_range("Index out of bounds");
		}
		return _array[index];
	}

	// Const subscript operator with bounds checking
	T const& operator[](int index) const {
		if (index < 0 || static_cast<size_t>(index) >= _size) {
			throw std::out_of_range("Index out of bounds");
		}
		return _array[index];
	}

	// Size member function
	size_t size() const {
		return _size;
	}
};

#endif
