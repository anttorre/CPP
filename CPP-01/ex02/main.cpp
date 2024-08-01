/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:55:08 by anttorre          #+#    #+#             */
/*   Updated: 2024/05/29 16:19:43 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;
	
	std::cout << "Memory address of the string variable: " << &str << "\nMemory address held by stringPTR: " << stringPTR << "\nMemory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "Value of the string variable: " << str << "\nValue pointed to by stringPTR: " << *stringPTR << "\nValue pointed to by stringREF: " << stringREF << std::endl;
}