/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:26:51 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/23 14:43:05 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main()
{
	Base *a = generate();
	identify(a);
	identify(*a);
	if (a)
		std::cout << "Private field class type: "<< a->getType() << std::endl;
	delete a;
}
