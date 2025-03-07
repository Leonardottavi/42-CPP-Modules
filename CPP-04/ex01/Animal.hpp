/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:00:39 by lottavi           #+#    #+#             */
/*   Updated: 2025/02/05 20:00:39 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal& other);
	virtual ~Animal();
	Animal& operator=(const Animal& other);

	virtual void makeSound() const;
	std::string getType() const;
};

#endif
