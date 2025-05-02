/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:29:08 by lottavi           #+#    #+#             */
/*   Updated: 2025/05/02 15:29:08 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>

Base* generate(void) {
    int r = rand() % 3;
    switch (r) {
        case 0: return new A();
        case 1: return new B();
        default: return new C();
    }
}
