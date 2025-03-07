/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:38:50 by lottavi           #+#    #+#             */
/*   Updated: 2025/02/05 20:38:50 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);

	virtual void makeSound() const;
	Brain* getBrain() const;

private:
	Brain* brain;
};

#endif
