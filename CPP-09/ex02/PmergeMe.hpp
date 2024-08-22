/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:02:18 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/22 12:29:08 by anttorre         ###   ########.fr       */
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
		std::list<int>& getList();
		std::vector<int>& getVector();
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

template<typename T>
void PmergeMeContainer(typename T::iterator begin, typename T::iterator end) {
    if (std::distance(begin, end) < 2)
		return;

    typename T::iterator mid = begin;
    std::advance(mid, std::distance(begin, end) / 2);

    PmergeMeContainer<T>(begin, mid);
    PmergeMeContainer<T>(mid, end);

    T left(begin, mid);
    T right(mid, end);

    typename T::iterator left_it = left.begin();
    typename T::iterator right_it = right.begin();
    typename T::iterator dest_it = begin;

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it < *right_it) {
            *dest_it = *left_it;
            ++left_it;
        } else {
            *dest_it = *right_it;
            ++right_it;
        }
        ++dest_it;
    }

    while (left_it != left.end()) {
        *dest_it = *left_it;
        ++left_it;
        ++dest_it;
    }

    while (right_it != right.end()) {
        *dest_it = *right_it;
        ++right_it;
        ++dest_it;
    }
}

#endif