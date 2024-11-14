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

# include <iostream>

class Fixed
{
	private:
		static const int	_num_frac_bits = 8;
		int					_fix_point_value;
	public:
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

# endif
