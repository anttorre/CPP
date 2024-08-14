/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:19:50 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/14 12:45:19 by anttorre         ###   ########.fr       */
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

static std::string trim(const std::string& str) {
	if (str.empty()) {
        return str;
    }
    std::string::size_type start = 0;
    while (start < str.length() && std::isspace(str[start])) {
        ++start;
    }
    if (start == str.length()) {
        return "";
    }
    std::string::size_type end = str.length() - 1;
    while (end > start && std::isspace(str[end])) {
        --end;
    }
    return str.substr(start, end - start + 1);
}

bool BitcoinExchange::check_file(std::string f)
{
	std::ifstream f1(f.c_str());
	std::string line;
	std::string date;
	std::string value;
	int code = 0;
	while (std::getline(f1, line))
	{
		std::string::size_type i = line.find("|");
		date = trim(line.substr(0, i));
		value = trim(line.substr(i + 1));
		if (i == std::string::npos)
			value = "";
		if (date == "date" && value == "value")
			continue;
		checkDateValue(date, value, &code);
		getDataValue(date, value, &code);
		code = 0;
	}
	f1.close();
	return true;
}

void	BitcoinExchange::checkDateValue(std::string date, std::string value, int *f)
{
	unsigned long int index = date.find("-");
	std::string year = date.substr(0, index);
	int index2 = date.find("-", index + 1);
	std::string month = date.substr(index + 1, index2 - index - 1);
	std::string day = date.substr(index2 + 1);
	if (atof(year.c_str()) < 2009)
		*f = 4;
	else if (atof(month.c_str()) < 1 || atof(month.c_str()) > 12)
		*f = 1;
	else
	{
		if (!checkDay(year, month, day))
			*f = 1;
	}
	if (date.empty())
		*f = 1;
	else if (!validDouble(value))
		*f = 1;
	else if (value.empty())
		*f = 1;
	else if (!value.empty() && atof(value.c_str()) < 0)
		*f = 2;
	else if (!value.empty() && atof(value.c_str()) > 1000)
		*f = 3;
}

bool BitcoinExchange::validDouble(std::string v)
{
	int points = 0;
	if (v.empty())
		return false;
	else
	{
		for (size_t i = 0; i < v.length(); i++)
			if (v[i] == '.')
				points++;
	}
	if (points > 1)
		return false;
	return true;
}

bool	BitcoinExchange::checkDay(std::string y, std::string m, std::string d)
{
	int month = atof(m.c_str());
	int year = atof(y.c_str());
	switch ((int)month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if (atof(d.c_str()) > 31 || atof(d.c_str()) <= 0)
				return (false);
			break ;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (atof(d.c_str()) > 30 || atof(d.c_str()) <= 0)
				return (false);
			break ;
		}
		case 2:
		{
			if (year % 400 == 0 || (year % 4 == 0 && (year % 100 != 0)))
			{
				if (atof(d.c_str()) > 29 || atof(d.c_str()) <= 0)
					return (false);
			}
			else
			{
				if (atof(d.c_str()) > 28 || atof(d.c_str()) <= 0)
					return (false);
			}
			break ;
		}
		default:
			return (false);
	}
	return (true);
}

void	BitcoinExchange::getDataValue(std::string date, std::string value, int *f)
{
	try
	{
		double n = atof(value.c_str());
		if (*f == BADINPUT)
			throw BadInput();
		if (*f == NEGATIVE)
			throw NegativeValue();
		if (*f == LARGENUMBER)
			throw LargeNumber();
		if (*f == BADDATE)
			throw BadDate();
	time_t targetDate = this->makeDate(date);
	double totalValue = 0;
    std::map<time_t, double>::iterator it = this->_data.lower_bound(targetDate);

	if (it != this->_data.end())
	{
		if (it->first == targetDate)
			totalValue = n * it->second;
		else if (it != this->_data.begin())
		{
			std::map<time_t, double>::iterator prevIt = it;
			--prevIt;
			totalValue = n * prevIt->second;
		}
		else
			totalValue = n * it->second;
	}
	else if (!this->_data.empty())
		totalValue = n * this->_data.rbegin()->second;
    std::cout << date << " => " << value << " = " << totalValue << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
		if (*f == BADINPUT || *f == BADDATE)
		{
			if (!date.empty())
				std::cerr << " => " << date;
			if (!value.empty())
				std::cerr << " => " << value;
		}
		std::cerr << std::endl;
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

const char * BitcoinExchange::BadDate::what() const throw()
{
	return "Error: bad date";
}