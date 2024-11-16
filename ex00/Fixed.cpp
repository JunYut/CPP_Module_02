/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:46:10 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/11/16 23:44:05 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	_fix_point_value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	cout << "Copy constructor called" << endl;
	setRawBits(other.getRawBits());
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed &Fixed::operator = (const Fixed &other)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &other)
		setRawBits(other.getRawBits());
	return (*this);
}

// const after argument(s) means the function does not modify the object
int	Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (_fix_point_value);
}

void	Fixed::setRawBits(const int raw)
{
	_fix_point_value = raw;
}
