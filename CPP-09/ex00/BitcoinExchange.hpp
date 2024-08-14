/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:07:32 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/14 12:38:29 by anttorre         ###   ########.fr       */
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
# define BADINPUT 1
# define NEGATIVE 2
# define LARGENUMBER 3
# define BADDATE 4

class BitcoinExchange
{
    private:
		std::map<time_t, double>	_data;
		bool	check_files(std::string file, std::string db);
		void	savedb(std::string db);
		bool	check_file(std::string f);
		time_t makeDate(const std::string& fechaStr);
		void	checkDateValue(std::string date, std::string value, int *f);
		bool	checkDay(std::string y, std::string m, std::string d);
		void	getDataValue(std::string date, std::string value, int *f);
		bool validDouble(std::string v);
	
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
		class BadDate : public std::exception
		{
			const char * what() const throw();
		};
};

#endif