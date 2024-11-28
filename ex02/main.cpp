/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:42:42 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/11/28 14:32:54 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using std::cout;
using std::endl;

int main(void) 
{
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

		// Expected output:
		// 0
		// 0.00390625
		// 0.00390625
		// 0.00390625
		// 0.0078125
		// 10.1016
		// 10.1016
	}

	Fixed a(5);
	Fixed b(0.5f);
	
	cout << "a: " << a << endl;
	cout << "a + a: " << a + a << endl;
	cout << "a - a: " << a - a << endl;
	cout << "a * a: " << a * a << endl;
	cout << "a / a: " << a / a << endl;
	cout << "++a: " << ++a << endl;
	cout << "--a: " << --a << endl;
	cout << "a++: " << a++ << endl;
	cout << "a++: " << a << endl;
	cout << "a--: " << a-- << endl;
	cout << "a--: " << a << endl;
	cout << "a > b: " << (a > b) << endl;
	cout << "a < b: " << (a < b) << endl;
	cout << "a >= b: " << (a >= b) << endl;
	cout << "a <= b: " << (a <= b) << endl;
	cout << "a == b: " << (a == b) << endl;
	cout << "a != b: " << (a != b) << endl;
	cout << "min(a, b): " << Fixed::min(a, b) << endl;
	cout << "max(a, b): " << Fixed::max(a, b) << endl;

	return 0;
}
