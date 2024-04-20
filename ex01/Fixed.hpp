/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:12:23 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/04/20 20:05:51 by vkhrabro         ###   ########.fr       */
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
		Fixed &operator = (const Fixed& src); // Assignment operator constructor
		Fixed(const int raw);
		Fixed(const float raw);
		~Fixed(); // el destructor

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat ( void ) const;
	int toInt ( void ) const;
	
};

std::ostream &operator<<(std::ostream &output, const Fixed &f);

#endif