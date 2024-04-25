/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:11:57 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/04/25 21:56:51 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

// const Point a(0.0f, 0.0f);
// const Point b(20.0f, 0.0f);
// const Point c(0.0f, 30.0f);
// const Point p(5.0f, 5.0f);

// std::cout << bsp(a, b, c, p) << std::endl;

//  const Point g(0.0f, 0.0f);
//         const Point h(-20.0f, 20.0f);
//         const Point t(20.0f, 20.0f);
//         const Point k(5.0f, 5.0f);

//         std::cout << bsp(g, h, t, k) << std::endl;

const Point a(0.0f, 0.0f);
        const Point b(20.0f, 0.0f);
        const Point c(10.0f, 30.0f);
        const Point p(0.0f, 00.0f);

        std::cout << bsp(a, b, c, p) << std::endl;

return 0;

}