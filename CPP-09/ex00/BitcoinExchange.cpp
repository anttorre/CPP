/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:19:50 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/07 17:10:04 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange &other)
{
    if (this != &other)
	{
		this->_data = other._data;
	}
	return *this;
}

void BitcoinExchange::init(std::string file, std::string db)
{
	if (!check_files(file, db))
		std::cout << "Error: could not open file." << std::endl;
	savedb(db);
	check_file(file);
}

bool BitcoinExchange::check_files(std::string file, std::string db)
{
	std::ifstream f1(file.c_str());
	std::ifstream f2(db.c_str());
	return f1.is_open() && f2.is_open();
}

void	BitcoinExchange::savedb(std::string db)
{
	std::ifstream f1(db.c_str());
	std::string line;
	while (std::getline(f1, line))
	{
		int indexComa = line.find(",");
		std::string key(line.substr(0, indexComa));
		std::string value(line.substr(indexComa + 1, line.length() - indexComa + 1));
		this->_data.insert(std::pair<time_t, double>(makeDate(key), atof(value.c_str())));
	}
}

bool BitcoinExchange::check_file(std::string f)
{
	std::ifstream f1(f.c_str());
	return true;
}

time_t BitcoinExchange::makeDate(const std::string& fechaStr)
{
    struct tm fecha = {};
    std::istringstream ss(fechaStr);
    char delimiter;

    ss >> fecha.tm_year >> delimiter >> fecha.tm_mon >> delimiter >> fecha.tm_mday;
    fecha.tm_year -= 1900;
    fecha.tm_mon -= 1;
    return mktime(&fecha);
}