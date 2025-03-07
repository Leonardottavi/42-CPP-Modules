/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:32:32 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/14 16:58:00 by lottavi          ###   ########.fr       */
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
	~Zombie();

	void announce() const;
	void setName(const std::string& zombieName);
};

Zombie* zombieHorde(int N, const std::string& name);

#endif // ZOMBIE_HPP
