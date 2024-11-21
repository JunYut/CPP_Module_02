/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:00:33 by we                #+#    #+#             */
/*   Updated: 2024/11/14 11:59:19 by tjun-yu          ###   ########.fr       */
/*                                                      	                      */
/* ************************************************************************** */

# pragma once
# ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
	private:
		static const int	_bits = 8;
		int					_raw_bits;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		
		Fixed	&operator = (const Fixed &other);

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		float	toFloat(void) const;
		int		toInt(void) const;

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

std::ostream	&operator << (std::ostream &stream, const Fixed &f);

# endif
