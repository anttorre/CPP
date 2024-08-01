/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:06:53 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/19 15:25:56 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
int main()
{
	std::cout << "ARRAY TYPE INT\n";
	int arr[] = {1, 2, 3, 4, 5};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	iter(arr, size, print);
	
	std::cout << "\nARRAY TYPE STRING\n";
	std::string arr1[] = {"hola", "adios", "42", "Malaga", "2024"};
	size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
	iter(arr1, size1, print);
	
	std::cout << "\nARRAY TYPE DOUBLE\n";
	double arr2[] = {1.1, 1.2, 1.3, 1.4, 1.5};
	size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
	iter(arr2, size2, print);
	return 0;
}
