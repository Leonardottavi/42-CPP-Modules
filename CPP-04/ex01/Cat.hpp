/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:59:49 by lottavi           #+#    #+#             */
/*   Updated: 2025/02/05 19:59:49 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);

	virtual void makeSound() const;
	Brain* getBrain() const;

private:
	Brain* brain;
};

#endif
