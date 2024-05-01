/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:32:29 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/05/01 19:01:06 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0){}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY()) {}

float Point::getX() const{
	return (this->_x.toFloat());
}

float Point::getY() const{
	return (this->_y.toFloat());
}

Point &Point::operator = (const Point& src){
	(void)src;
	return *this;
}

Point::~Point(){}