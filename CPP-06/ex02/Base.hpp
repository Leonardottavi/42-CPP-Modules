/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:23:55 by lottavi           #+#    #+#             */
/*   Updated: 2025/07/07 10:59:16 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
public:
	Base();
	Base(const Base& other);
	Base& operator=(const Base& other);
	virtual ~Base();
};

class A : public Base {
public:
	A();
	A(const A& other);
	A& operator=(const A& other);
	virtual ~A();
};

class B : public Base {
public:
	B();
	B(const B& other);
	B& operator=(const B& other);
	virtual ~B();
};

class C : public Base {
public:
	C();
	C(const C& other);
	C& operator=(const C& other);
	virtual ~C();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
