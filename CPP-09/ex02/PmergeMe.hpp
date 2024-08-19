/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:02:18 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/19 17:13:03 by anttorre         ###   ########.fr       */
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
		PmergeMe();
    public:
        PmergeMe(const char **argv);
        PmergeMe(const PmergeMe &other);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe &other);
		void	printNumbers();
		int getLen() const;
		bool check_duplicates(std::list<int>::iterator begin, std::list<int>::iterator end);
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
		class DuplicatedNumbers : public std::exception
		{
			const char * what() const throw();
		};
};

#endif