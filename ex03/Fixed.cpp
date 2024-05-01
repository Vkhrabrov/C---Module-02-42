/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:12:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/05/01 19:00:22 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed() : _fp_value(0){}

Fixed::Fixed(const Fixed &copy){
	*this = copy;
}

Fixed &Fixed::operator = ( const Fixed &src){
	if (this != &src)
		this->_fp_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed(){}

int Fixed::getRawBits(void) const{
	return this->_fp_value;
}

void Fixed::setRawBits(int const raw){
	this->_fp_value = raw;
}

Fixed::Fixed(const int raw) {
    this->_fp_value = raw << this->_fract_bits;
}


Fixed::Fixed(const float raw){
	this->_fp_value = roundf(raw * (1 << this->_fract_bits));
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
	this->_fp_value += 1;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed temp = *this;
	this->_fp_value += 1;
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
