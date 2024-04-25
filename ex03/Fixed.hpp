/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:12:23 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/04/24 21:48:00 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed{

	private:
		int _fp_value;
		static const int _fract_bits;

	public:
		Fixed(); // default constructor
		Fixed(const Fixed& copy); // Copy Default constructor
		Fixed(const int raw);
		Fixed(const float raw);
		~Fixed(); // el destructor

		Fixed &operator = (const Fixed& src); 

		bool operator==(const Fixed& src) const;
		bool operator!=(const Fixed& src) const;
		bool operator>(const Fixed& src) const;
		bool operator<(const Fixed& src) const;
		bool operator>=(const Fixed& src) const;
		bool operator<=(const Fixed& src) const;

		Fixed operator+(const Fixed& src);
		Fixed operator-(const Fixed& src);
		Fixed operator*(const Fixed& src);
		Fixed operator/(const Fixed& src);

		Fixed& operator++();
		Fixed operator++(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat ( void ) const;
		int toInt ( void ) const;

		

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
	
};

std::ostream &operator<<(std::ostream &output, const Fixed &f);

#endif