/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:02:18 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/19 16:55:09 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <list>
# include <vector>
# include <cstring>
# include <climits>
# include <cstdlib>

class PmergeMe
{
    private:
		std::list<int> _list;
		std::vector<int> _vector;
		int _len;
		PmergeMe();
    public:
        PmergeMe(const char **argv);
        PmergeMe(const PmergeMe &other);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe &other);
		void	printNumbers();
		int getLen() const;
		class EmptyString : public std::exception
		{
			const char * what() const throw();
		};
		class NotADigit : public std::exception
		{
			const char * what() const throw();
		};
		class IntOverflow : public std::exception
		{
			const char * what() const throw();
		};
		class NegativeValue : public std::exception
		{
			const char * what() const throw();
		};
};

#endif