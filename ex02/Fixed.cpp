/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:46:10 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/11/28 14:59:21 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	_raw_bits = 0;
}

Fixed::Fixed(const Fixed &other)
{
	cout << "Copy constructor called" << endl;
	*this = other;
}

Fixed::Fixed(const int num)
{
	cout << "Int constructor called" << endl;
	_raw_bits = num << _bits;
}

Fixed::Fixed(const float num)
{
	cout << "Float constructor called" << endl;
	_raw_bits = roundf(num * (1 << _bits));
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

bool	Fixed::operator > (const Fixed &other) const
{
	return (_raw_bits > other.getRawBits());
}

bool	Fixed::operator < (const Fixed &other) const
{
	return (_raw_bits < other.getRawBits());
}

bool	Fixed::operator >= (const Fixed &other) const
{
	return (_raw_bits >= other.getRawBits());
}

bool	Fixed::operator <= (const Fixed &other) const
{
	return (_raw_bits <= other.getRawBits());
}

bool	Fixed::operator == (const Fixed &other) const
{
	return (_raw_bits == other.getRawBits());
}

bool	Fixed::operator != (const Fixed &other) const
{
	return (_raw_bits != other.getRawBits());
}

Fixed	Fixed::operator + (const Fixed &other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed	Fixed::operator - (const Fixed &other) const
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed	Fixed::operator * (const Fixed &other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed	Fixed::operator / (const Fixed &other) const
{
	return (Fixed(toFloat() / other.toFloat()));
}

Fixed	&Fixed::operator ++ (void)
{
	_raw_bits += 1;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	tmp(*this);
	++(*this);
	return (tmp);
}

Fixed	&Fixed::operator -- (void)
{
	_raw_bits -= 1;
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	tmp(*this);
	--(*this);
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_raw_bits) / (1 << _bits));
}

int	Fixed::toInt(void) const
{
	return (_raw_bits >> _bits);
}

int	Fixed::getRawBits(void) const
{
	return (_raw_bits);
}

void	Fixed::setRawBits(const int raw)
{
	_raw_bits = raw;
}

std::ostream	&operator << (std::ostream &stream, const Fixed &f)
{
	stream << f.toFloat();
	return (stream);
}
