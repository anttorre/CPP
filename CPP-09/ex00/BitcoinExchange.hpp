/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:07:32 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/08 16:46:39 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <ctime>
# include <cstdlib>

class BitcoinExchange
{
    private:
		std::map<time_t, double>	_data;
		bool	check_files(std::string file, std::string db);
		void	savedb(std::string db);
		bool	check_file(std::string f);
		time_t makeDate(const std::string& fechaStr);
		void	check_date(time_t t, int *f);
	
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange &other);
        ~BitcoinExchange();
        BitcoinExchange& operator=(BitcoinExchange &other);
		void	init(std::string file, std::string db);
		class NegativeValue : public std::exception
		{
			const char * what() const throw();
		};
		class BadInput : public std::exception
		{
			const char * what() const throw();
		};
		class LargeNumber : public std::exception
		{
			const char * what() const throw();
		};
};

static std::string trim(const std::string& str) {
    std::string::const_iterator start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        ++start;
    }
    std::string::const_iterator end = str.end();
    do {
        --end;
    } while (end != start && std::isspace(*end));
    return std::string(start, end + 1);
}

#endif