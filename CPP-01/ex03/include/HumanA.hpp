/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumaA.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:33:21 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/15 15:46:04 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
private:
	std::string name;
	Weapon& weapon;

public:
	HumanA(const std::string& name, Weapon& weapon);
	void attack() const;
};

#endif // HUMANA_HPP
