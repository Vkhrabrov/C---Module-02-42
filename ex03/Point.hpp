/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:29:51 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/04/28 22:17:01 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

	private:

		const Fixed _x;
		const Fixed _y;

	public:

	Point();
	Point(const float x, const float y);
	Point(const Point& copy);

	Point &operator = (const Point& src);

	~Point();

	float getX() const;
	float getY() const;

};

#endif