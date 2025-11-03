/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 08:58:24 by lottavi           #+#    #+#             */
/*   Updated: 2025/11/03 09:59:45 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
	{
		if (i != 4 && i != 7)
		{
			if (!isdigit(date[i]))
				return false;
		}
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || year > 2200)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const
{
	std::istringstream iss(valueStr);
	if (!(iss >> value))
		return false;

	if (value < 0.0)
		return false;
	if (value > 1000.0)
		return false;

	return true;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);

	if (it != _exchangeRates.end() && it->first == date)
		return date;

	if (it == _exchangeRates.begin())
		return "";

	--it;
	return it->first;
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return false;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t delimPos = line.find(',');
		if (delimPos == std::string::npos)
			continue;

		std::string date = line.substr(0, delimPos);
		std::string rateStr = line.substr(delimPos + 1);

		double rate = std::atof(rateStr.c_str());
		_exchangeRates[date] = rate;
	}

	file.close();
	return true;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _exchangeRates.find(date);

	if (it != _exchangeRates.end())
		return it->second;

	std::map<std::string, double>::const_iterator lower = _exchangeRates.lower_bound(date);

	if (lower == _exchangeRates.begin())
		return -1;

	--lower;
	return lower->second;
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t delimPos = line.find(',');

		if (delimPos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string dateStr = line.substr(0, delimPos);
		std::string valueStr = line.substr(delimPos + 1);

		// Trim spaces
		size_t start = dateStr.find_first_not_of(" \t");
		size_t end = dateStr.find_last_not_of(" \t");
		if (start != std::string::npos)
			dateStr = dateStr.substr(start, end - start + 1);

		start = valueStr.find_first_not_of(" \t");
		end = valueStr.find_last_not_of(" \t");
		if (start != std::string::npos)
			valueStr = valueStr.substr(start, end - start + 1);

		if (!isValidDate(dateStr))
		{
			std::cout << "Error: bad input => " << dateStr << std::endl;
			continue;
		}

		double value;
		if (!isValidValue(valueStr, value))
		{
			if (value < 0.0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (value > 1000.0)
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << "Error: bad input." << std::endl;
			continue;
		}

		std::string closestDate = findClosestDate(dateStr);

		if (closestDate.empty())
		{
			std::cout << "Error: bad input => " << dateStr << std::endl;
			continue;
		}

		double exchangeRate = _exchangeRates[closestDate];
		double result = value * exchangeRate;

		std::cout << dateStr << " => " << value << " = " << result << std::endl;
	}

	file.close();
}
