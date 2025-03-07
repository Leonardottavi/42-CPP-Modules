/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:40:19 by lottavi           #+#    #+#             */
/*   Updated: 2025/02/05 19:40:19 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); // Cat sound
	j->makeSound(); // Dog sound
	meta->makeSound(); // Animal sound

	delete meta;
	delete j;
	delete i;

	// Test WrongAnimal and WrongCat
	const WrongAnimal* wrong = new WrongCat();
	std::cout << wrong->getType() << std::endl;
	wrong->makeSound(); // WrongAnimal sound
	delete wrong;

	return 0;
}
