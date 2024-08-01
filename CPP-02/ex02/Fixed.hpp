/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:18:31 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/07 17:23:25 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _bits = 8;

	public:
		/* Canonical Orthodox Form Class */
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		
		/* Other constructors */
		Fixed(const int integer);
		Fixed(const float floating);

		/* Getters */
		int		getRawBits(void) const;

		/* Setters */
		void	setRawBits(const int raw);

		/* Functions */
		static	float pow(float base, int exp);
		float	toFloat(void) const;
		int		toInt(void) const;
		
		/* Comparison operators */
		bool	operator>(Fixed const &n);
		bool	operator<(Fixed const &n);
		bool	operator>=(Fixed const &n);
		bool	operator<=(Fixed const &n);
		bool	operator==(Fixed const &n);
		bool	operator!=(Fixed const &n);
		
		/* Arithmetic operators */
		Fixed	operator+(Fixed const &n) const;
		Fixed	operator-(Fixed const &n) const;
		Fixed	operator*(Fixed const &n) const;
		Fixed	operator/(Fixed const &n) const;

		/* Increment & Decrement operators */
		Fixed	operator++(int);
		Fixed&	operator++(void);
		Fixed	operator--(int);
		Fixed&	operator--(void);

		/* Min & Max */
		static Fixed& min( Fixed &a, Fixed &b );
		static const Fixed& min( const Fixed &a, const Fixed &b );
		static Fixed& max( Fixed &a, Fixed &b );
		static const Fixed& max( const Fixed &a, const Fixed &b );
};

std::ostream &operator<<(std::ostream &out, Fixed const &i);