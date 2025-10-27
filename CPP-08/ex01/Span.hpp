/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:28:07 by lottavi           #+#    #+#             */
/*   Updated: 2025/10/27 12:28:56 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <limits>
# include <cstdlib>

class Span {
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

		Span();

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end) {
			while (begin != end) {
				if (_numbers.size() >= _maxSize) {
					throw SpanFullException();
				}
				_numbers.push_back(*begin);
				++begin;
			}
		}

		int shortestSpan() const;
		int longestSpan() const;

		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Span is full, cannot add more numbers";
				}
		};

		class NoSpanException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Not enough numbers to calculate span";
				}
		};
};

#endif
