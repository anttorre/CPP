/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:09:12 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/21 15:43:05 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./program_name <arguments>.\nExample: ./program 5 8 6 9 2" << std::endl;
		return 1;
	}
	try
	{
		clock_t start;
		clock_t end;
		double timeList;
		double timeVector;
		
		PmergeMe pm(argv);
		std::cout << "Before: ";
		pm.printNumbers();
		start = clock();
		PmergeMeContainer<std::list<int> >(pm.getList().begin(), pm.getList().end());
		end = clock();
		timeList = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
		start = clock();
		PmergeMeContainer<std::vector<int> >(pm.getVector().begin(), pm.getVector().end());
		end = clock();
		timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
		std::cout << "After: ";
		pm.printNumbers();
		std::cout << "Time to process a range of " << pm.getLen() << " elements with std::list<int> : " << timeList <<  " us" << std::endl;
		std::cout << "Time to process a range of " << pm.getLen() << " elements with std::vector<int> : " << timeVector <<  " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}