/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 08:58:24 by lottavi           #+#    #+#             */
/*   Updated: 2025/11/03 09:59:50 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _exchangeRates;

		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		bool isValidDate(const std::string& date) const;
		bool isValidValue(const std::string& valueStr, double& value) const;
		std::string findClosestDate(const std::string& date) const;

	public:
		BitcoinExchange();
		~BitcoinExchange();

		bool loadDatabase(const std::string& filename);
		void processInputFile(const std::string& filename);
		double getExchangeRate(const std::string& date) const;
};

#endif
