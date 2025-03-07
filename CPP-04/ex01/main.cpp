/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:59:04 by lottavi           #+#    #+#             */
/*   Updated: 2025/02/06 14:26:48 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	// Additional tests
	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog(*dog1);
	dog1->makeSound();
	dog2->makeSound();
	dog1->getBrain()->setIdea(0, "Chase the cat");
	std::cout << "Dog1's idea: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2's idea: " << dog2->getBrain()->getIdea(0) << std::endl;
	delete dog1;
	delete dog2;

	Cat* cat1 = new Cat();
	Cat* cat2 = new Cat(*cat1);
	cat1->makeSound();
	cat2->makeSound();
	cat1->getBrain()->setIdea(0, "Climb the tree");
	std::cout << "Cat1's idea: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2's idea: " << cat2->getBrain()->getIdea(0) << std::endl;
	delete cat1;
	delete cat2;

	return 0;
}
