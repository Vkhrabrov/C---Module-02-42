/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:35:08 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/04/28 21:57:07 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float area(Point const a, Point const b, Point const c){
	return abs(0.5 * (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())));
}

bool bsp( Point const a, Point const b, Point const c, Point const point){

	float mainTriangle = area(a, b, c);
	float A = area(a, b, point);
	float B = area(b, c, point);
	float C = area(a, c, point);

	std::cout << "The area of the main triangle - " << mainTriangle << std::endl;
	std::cout << "The area of the triangle A - " << A << std::endl;
	std::cout << "The area of the triangle B - " << B << std::endl;
	std::cout << "The area of the triangle C - " << C << std::endl << std::endl;

	if ((mainTriangle == A + B + C) && (A != 0 && B != 0 && C != 0))
    	return true;

	return false;

}