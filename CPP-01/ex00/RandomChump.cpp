/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomChum.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:24:21 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/14 15:51:40 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RandomChump.hpp"

// Function to create a zombie, name it, and announce itself
void RandomChump(std::string name) {
	Zombie z(name);
	z.announce();
}
