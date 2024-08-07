/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:07:32 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/07 17:09:54 by anttorre         ###   ########.fr       */
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
	
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange &other);
        ~BitcoinExchange();
        BitcoinExchange& operator=(BitcoinExchange &other);
		void	init(std::string file, std::string db);
};

#endif