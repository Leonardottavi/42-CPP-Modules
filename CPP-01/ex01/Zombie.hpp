/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:32:32 by lottavi           #+#    #+#             */
/*   Updated: 2025/07/07 10:59:16 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(const Zombie& other);
	Zombie& operator=(const Zombie& other);
	~Zombie();

	void announce() const;
	void setName(const std::string& zombieName);
};

Zombie* zombieHorde(int N, const std::string& name);

#endif // ZOMBIE_HPP
