/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:26:23 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/10 13:13:52 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <iostream>
# include <cstring>
# include <climits>
# include <cstdlib>

enum types
{
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
	PLF,
	PLD,
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &other);
		ScalarConverter& operator=(ScalarConverter& other);
	public:
		~ScalarConverter();
		static void	convert(std::string str);
};

#endif