/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:00:33 by we                #+#    #+#             */
/*   Updated: 2024/11/13 12:32:16 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		static const int	num_frac_bits = 8;
		int					fix_point_value;
	public:
		Fixed() : fix_point_value(0) {}
		Fixed(const Fixed &other);
		~Fixed() {}
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

# endif
