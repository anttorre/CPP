/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:19:50 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/08 17:16:40 by anttorre         ###   ########.fr       */
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
	bool open = f1.is_open() && f2.is_open();
	f1.close();
	f2.close();
	return open;
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
	f1.close();
}

bool BitcoinExchange::check_file(std::string f)
{
	std::ifstream f1(f.c_str());
	std::string line;
	std::string date;
	std::string value;
	int badInput = 0;
	while (std::getline(f1, line))
	{
		date = trim(line.substr(0, line.find("|")));
		value = trim(line.substr(line.find("|") + 1, line.length() - line.find("|") + 1));
		try
		{
			check_date(makeDate(date), &badInput);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	f1.close();
	return true;
}

void	BitcoinExchange::check_date(time_t t, int *f)
{
	tm* timeinfo = localtime(&t);
	timeinfo->tm_year += 1900;
	timeinfo->tm_mon += 1;
	if (timeinfo->tm_year < 2009)
	{
		*f = 1;
		throw BadInput();
	}
	else if (timeinfo->tm_mon < 1 || timeinfo->tm_mon > 12)
	{
		*f = 1;
		throw BadInput();
	}
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

const char * BitcoinExchange::NegativeValue::what() const throw()
{
	return "Error: not a positive number.";
}

const char * BitcoinExchange::BadInput::what() const throw()
{
	return "Error: bad input";
}

const char * BitcoinExchange::LargeNumber::what() const throw()
{
	return "Error: too large a number.";
}