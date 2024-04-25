/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:35:08 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/04/25 21:51:41 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float area(Point const a, Point const b, Point const c){
	return (0.5*(a.getX()*(b.getY()-c.getY())) + b.getX()*(c.getY()-a.getY()) + c.getX()*(a.getY() - b.getY()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point){

	float mainTriangle = area(a, b, c);
	float aTriangle = area(a, b, point);
	float bTriangle = area(b, c, point);
	float cTriangle = area(a, c, point);

	if (mainTriangle == aTriangle + bTriangle + cTriangle)
		return true;
	return false;

}