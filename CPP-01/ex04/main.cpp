/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:09:34 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/20 14:21:39 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

std::string ft_replace(const std::string& content, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t pos = 0;
	size_t prev_pos = 0;

	while ((pos = content.find(s1, prev_pos)) != std::string::npos)
	{
		result.append(content, prev_pos, pos - prev_pos);
		result.append(s2);
		prev_pos = pos + s1.length();
	}
	result.append(content, prev_pos, std::string::npos);

	return result;
}

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		throw std::runtime_error("Could not open input file");
	}

	std::ostringstream buffer;
	buffer << inputFile.rdbuf();
	std::string content = buffer.str();
	inputFile.close();

	std::string result = ft_replace(content, s1, s2);

	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open())
	{
		throw std::runtime_error("Could not open output file");
	}

	outputFile << result;
	outputFile.close();
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	try
	{
		replaceInFile(argv[1], argv[2], argv[3]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
