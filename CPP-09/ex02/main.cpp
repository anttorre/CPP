/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:09:12 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/19 16:54:36 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	clock_t start;
	clock_t end;
	double timeList;
	double timeVector;
	
	if (argc < 2)
	{
		std::cerr << "Usage: ./program_name <arguments>.\nExample: ./program 5 8 6 9 2" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe pm(argv);
		std::cout << "Before: ";
		pm.printNumbers();
		start = clock();
		/*merge list*/
		end = clock();
		timeList = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		start = clock();
		/*merge vector*/
		end = clock();
		timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "After: ";
		pm.printNumbers();
		std::cout << "Time to process a range of " << pm.getLen() << " elements with std::list<int> : " << timeList <<  "us" << std::endl;
		std::cout << "Time to process a range of " << pm.getLen() << " elements with std::vector<int> : " << timeVector <<  "us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

/*
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
*/
