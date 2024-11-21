/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:42:42 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/11/21 13:48:35 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using std::cout;
using std::endl;

int main(void) 
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	cout << a << endl;
	cout << ++a << endl;
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;
	cout << b << endl;
	cout << Fixed::max(a, b) << endl;

	return 0;
}
