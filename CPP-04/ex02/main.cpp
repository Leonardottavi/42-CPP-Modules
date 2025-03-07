/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:37:36 by lottavi           #+#    #+#             */
/*   Updated: 2025/02/06 14:30:01 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); // Outputs cat sound
	j->makeSound(); // Outputs dog sound

	delete j;
	delete i;

	// Test deep copies
	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "Original Dog Idea");
	Dog copyDog = originalDog;
	copyDog.getBrain()->setIdea(0, "Copied Dog Idea");

	Cat originalCat;
	originalCat.getBrain()->setIdea(0, "Original Cat Idea");
	Cat copyCat = originalCat;
	copyCat.getBrain()->setIdea(0, "Copied Cat Idea");

	std::cout << "Original Dog's Idea chase the cat: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy Dog's Idea chase the cat: " << copyDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Original Cat's Idea climb the tree: " << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy Cat's Idea clib the tree: " << copyCat.getBrain()->getIdea(0) << std::endl;

	return 0;
}
