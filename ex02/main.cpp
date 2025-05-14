/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:00:04 by amaligno          #+#    #+#             */
/*   Updated: 2025/05/14 18:36:53 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

using std::cout;
using std::string;

Base*	generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		cout << "p points to A object\n";
	else if (dynamic_cast<B*>(p))
		cout << "p points to B object\n";
	else if (dynamic_cast<C*>(p))
		cout << "p points to C object\n";
}

void	identify(Base& p)
{
	string	type;
	try
	{
		(void)dynamic_cast<A&>(p);
		type = "A";
	}
	catch(std::exception &e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		type = "B";
	}
	catch(std::exception &e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		type = "C";
	}
	catch(std::exception &e){}
	cout << "p is a reference to a " << type << " object\n";
}

int main()
{
	std::srand((unsigned) time(NULL));
	Base& ref= *generate();
	Base* ptr= generate();

	identify(ptr);
	identify(ref);
	
	delete &ref;
	delete ptr;
}