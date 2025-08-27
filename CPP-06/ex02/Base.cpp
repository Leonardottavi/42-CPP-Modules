/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:16:03 by lottavi           #+#    #+#             */
/*   Updated: 2025/07/07 10:59:16 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base() {}

Base::Base(const Base& other) {
	(void)other;
}

Base& Base::operator=(const Base& other) {
	(void)other;
	return *this;
}

Base::~Base() {}

A::A() : Base() {}

A::A(const A& other) : Base(other) {}

A& A::operator=(const A& other) {
	if (this != &other) {
		Base::operator=(other);
	}
	return *this;
}

A::~A() {}

B::B() : Base() {}

B::B(const B& other) : Base(other) {}

B& B::operator=(const B& other) {
	if (this != &other) {
		Base::operator=(other);
	}
	return *this;
}

B::~B() {}

C::C() : Base() {}

C::C(const C& other) : Base(other) {}

C& C::operator=(const C& other) {
	if (this != &other) {
		Base::operator=(other);
	}
	return *this;
}

C::~C() {}

Base*	generate(void) {
	int	r = rand() % 3;
	switch (r) {
		case 0: return new A();
		case 1: return new B();
		default: return new C();
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}
	std::cout << "Unknown" << std::endl;
}
