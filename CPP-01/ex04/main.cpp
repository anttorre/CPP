/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:59:26 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/04 18:04:41 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

int	main(int argc, char **argv)
{
	std::string		line = "";
	std::string		result = "";
	std::string		ar2;
	std::string		ar3;
	if (argc != 4)
	{
		std::cout << "Wrong arguments.\nUsage: <filename> <old_word> <new_word>" << std::endl;
		return (1);
	}
	if (argv[2])
		ar2 = std::string(argv[2]);
	if (argv[3])
		ar3 = std::string(argv[3]);
	if (ar2.empty() || ar3.empty())
	{
		std::cout << "Empty strings to replace" << std::endl;
		return (1);
	}
	std::ifstream	infile(argv[1]);
	if (!infile.is_open() )
	{
		std::cout << "Error opening INPUT file." << std::endl;
		return (1);
	}
	std::string		filename = argv[1];
	filename += ".replace";
	std::ofstream	outfile(filename.c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error opening OUTPUT file." << std::endl;
		return (1);
	}
	
	while (std::getline(infile, line))
	{
		size_t pos = 0;
		size_t initPos = line.find(ar2, pos);
		while (initPos != std::string::npos)
		{
			result += line.substr(pos, initPos - pos);
			result += ar3;
			pos = initPos + ar2.length();
			initPos = line.find(ar2, pos);
		}
		result += line.substr(pos);
		outfile << result << std::endl;
		result.clear();
	}
	infile.close();
	outfile.close();
}