/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:38:00 by lottavi           #+#    #+#             */
/*   Updated: 2025/02/05 20:38:00 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public:
	Brain();
	Brain(const Brain& other);
	~Brain();
	Brain& operator=(const Brain& other);

	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;

private:
	std::string ideas[100];
};

#endif
