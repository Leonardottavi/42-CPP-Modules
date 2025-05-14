/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:23:55 by lottavi           #+#    #+#             */
/*   Updated: 2025/05/14 16:12:42 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
public:
	virtual ~Base();
};

class A : public Base {virtual ~A() {}};
class B : public Base {virtual ~B() {}};
class C : public Base {virtual ~C() {}};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
