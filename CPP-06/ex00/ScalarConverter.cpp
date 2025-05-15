/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:42:13 by lottavi           #+#    #+#             */
/*   Updated: 2025/05/15 12:26:48 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

static bool	isPseudoFloat(const std::string &s) {
	return (s == "+inff" || s == "-inff" || s == "nanf");
}

static bool	isPseudoDouble(const std::string &s) {
	return (s == "+inf" || s == "-inf" || s == "nan");
}

static void	printChar(double d) {
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() ||
		isnan(d))
		std::cout << "char: impossible" << std::endl;
	else {
		char c = static_cast<char>(d);
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}

static void	printInt(double d) {
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() ||
		isnan(d) || isinf(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
}

static void	printFloat(double d) {
	if (isnan(d))
		std::cout << "float: nanf" << std::endl;
	else if (isinf(d)) {
		if (d > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	} else {
		float f = static_cast<float>(d);
		std::cout << "float: " << f << (f == static_cast<int>(f) ? ".0f" : "f") << std::endl;
	}
}

static void	printDouble(double d) {
	if (isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (isinf(d)) {
		if (d > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	} else {
		std::cout << "double: " << d << (d == static_cast<int>(d) ? ".0" : "") << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &literal) {
	// Check for single non-digit character
	if (literal.size() == 1 && !isdigit(literal[0])) {
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return;
	}

	// Handle pseudo-literals
	if (isPseudoFloat(literal)) {
		double d = (literal[0] == '-') ? -std::numeric_limits<double>::infinity()
									   : std::numeric_limits<double>::infinity();
		if (literal == "nanf") d = std::numeric_limits<double>::quiet_NaN();
		printChar(d);
		printInt(d);
		printFloat(d);
		printDouble(d);
		return;
	}
	if (isPseudoDouble(literal)) {
		double d = (literal[0] == '-') ? -std::numeric_limits<double>::infinity()
									   : std::numeric_limits<double>::infinity();
		if (literal == "nan") d = std::numeric_limits<double>::quiet_NaN();
		printChar(d);
		printInt(d);
		printFloat(d);
		printDouble(d);
		return;
	}

	// Try to parse as float or double
	char *end = 0;
	double d = std::strtod(literal.c_str(), &end);

	// If it ends with 'f', it's a float literal form
	if (*end == 'f' && end != literal.c_str()) {
		printChar(d);
		printInt(d);
		printFloat(d);
		printDouble(d);
		return;
	}
	// Otherwise treat as double or int
	if (*end == '\0') {
		printChar(d);
		printInt(d);
		printFloat(d);
		printDouble(d);
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
