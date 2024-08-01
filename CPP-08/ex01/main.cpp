/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:24:43 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/30 12:55:37 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		for (unsigned int i = 0; i < sp.getSize(); i++)
			std::cout << "Span[" << i << "] = " << sp.getNumber(i) << std::endl;
		//sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::vector<int> n;
		n.push_back(4);
		n.push_back(3);
		Span sp(3);
		sp.addNumber(2);
		sp.addNumber(n.begin(), n.end());
		sp.getNumber(0);
		for (unsigned int i = 0; i < sp.getSize(); i++)
			std::cout << sp.getNumber(i) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}