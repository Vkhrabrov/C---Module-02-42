/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:12:23 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/04/18 21:08:11 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Fixed{

	private:
		int _fp_value;
		static const int _fract_bits;

	public:
		Fixed(); // default constructor
		Fixed(const Fixed& copy); // Copy Default constructor
		Fixed &operator = (const Fixed& src); // Assignment operator constructor
		~Fixed(); // el destructor

	int getRawBits(void) const;
	void setRawBits(int const raw);
	
};