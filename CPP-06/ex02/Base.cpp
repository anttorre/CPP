/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:32:19 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/11 14:44:27 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{
}

Base::~Base()
{
}

std::string Base::getType() const
{
	return "Base";
}

Base *generate(void)
{
	Base *b = NULL;
	srand(time(0));
	int i = (rand() % 3) + 1;;
	switch (i)
	{
		case 1:
			return (b = new A());
		case 2:
			return (b = new B());
		case 3:
			return (b = new C());
	}
	return b;
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
        std::cout << "Type class A\n";
    else if(dynamic_cast<B*>(p))
        std::cout << "Type class B\n";
    else if(dynamic_cast<C*>(p))
        std::cout << "Type class C\n";
    else
        std::cout << "Type class Unknown\n";
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type class A\n";
    }
    catch (const std::exception&) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "Type class B\n";
        }
        catch (const std::exception&) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "Type class C\n";
            }
            catch (const std::exception&) {
                std::cout << "Type class Unknown\n";
            }
        }
    }
}