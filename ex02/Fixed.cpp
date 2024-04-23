/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:12:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/04/23 23:26:29 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 4;

Fixed::Fixed() : _fp_value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy; // using the assignment operator
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator = ( const Fixed &src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fp_value = src.getRawBits();
	
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fp_value;
}

void Fixed::setRawBits(int const raw){
	this->_fp_value = raw;
}

Fixed::Fixed(const int raw) {
    std::cout << "Int constructor called" << std::endl;
    this->_fp_value = raw << this->_fract_bits;
    // std::cout << "fixed-point value (int) is " << this->_fp_value << std::endl;

    // // Print binary representation
    // std::cout << "Binary representation: ";
    // for (int i = sizeof(_fp_value) * 4 - 1; i >= 0; i--) {
    //     std::cout << ((_fp_value >> i) & 1);
    // }
    // std::cout << std::endl;
}


Fixed::Fixed(const float raw){
	std::cout << "Float constructor called" << std::endl;
	this->_fp_value = roundf(raw * (1 << this->_fract_bits));
	// std::cout << "fixed-point value (float) is " << this->_fp_value << std::endl;
	// std::cout << "Binary representation: ";
    // for (int i = sizeof(_fp_value) * 8 - 1; i >= 0; i--) {
    //     std::cout << ((_fp_value >> i) & 1);
    // }
    // std::cout << std::endl;
}

float Fixed::toFloat(void) const {
	return (float(this->_fp_value) / (1 << this->_fract_bits));
}

int Fixed::toInt(void) const {
	return (int(this->_fp_value) / (1 << this->_fract_bits));
}

std::ostream &operator<<(std::ostream &output, const Fixed &f){
	output << f.toFloat();
	return output;
}

bool Fixed::operator==(const Fixed& src) const{
	return (this->_fp_value == src._fp_value);
}
bool Fixed::operator!=(const Fixed& src) const{
	return (this->_fp_value != src._fp_value);
}
bool Fixed::operator>(const Fixed& src) const{
	return (this->_fp_value > src._fp_value);
}
bool Fixed::operator<(const Fixed& src) const{
	return (this->_fp_value < src._fp_value);
}
bool Fixed::operator>=(const Fixed& src) const{
	return (this->_fp_value >= src._fp_value);
}
bool Fixed::operator<=(const Fixed& src) const{
	return (this->_fp_value <= src._fp_value);
}

Fixed Fixed::operator+(const Fixed& src){
	return(this->toFloat() + src.toFloat());
}
Fixed Fixed::operator-(const Fixed& src){
	return(this->toFloat() - src.toFloat());
}
Fixed Fixed::operator/(const Fixed& src){
	return(this->toFloat() / src.toFloat());
}
Fixed Fixed::operator*(const Fixed& src){
	return(this->toFloat() * src.toFloat());
}

Fixed &Fixed::operator++(){
	int epsilon = 1 << _fract_bits;
	this->_fp_value += epsilon;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed temp = *this;
	int epsilon = 1 << _fract_bits;
	this->_fp_value += epsilon;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
if (a > b)
		return a;
	return b;
}
