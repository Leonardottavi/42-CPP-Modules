/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:24:02 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/14 15:51:22 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewZombie.hpp"

// Function to create a new zombie and return a pointer to it
Zombie* NewZombie(std::string name) {
	return new Zombie(name);
}
