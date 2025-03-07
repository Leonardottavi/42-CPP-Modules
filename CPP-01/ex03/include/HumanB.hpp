/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:33:54 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/15 15:46:19 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
	Weapon* weapon;

public:
	HumanB(const std::string& name);
	void setWeapon(Weapon& weapon);
	void attack() const;
};

#endif // HUMANB_HPP
