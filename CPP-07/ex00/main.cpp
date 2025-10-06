/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:14:28 by lottavi           #+#    #+#             */
/*   Updated: 2025/10/06 11:10:39 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

int main( void ) {
	int a, b;

	std::cout << "Inserisci il primo numero intero (a): ";
	std::cin >> a;
	std::cout << "Inserisci il secondo numero intero (b): ";
	std::cin >> b;

	std::cout << "\nValori iniziali: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c, d;

	std::cout << "\nInserisci la prima stringa (c): ";
	std::cin >> c;
	std::cout << "Inserisci la seconda stringa (d): ";
	std::cin >> d;

	std::cout << "\nValori iniziali: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
