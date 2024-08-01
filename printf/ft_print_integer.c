/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:42:21 by nyrandri          #+#    #+#             */
/*   Updated: 2024/05/02 12:34:46 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_integer(int number)
{
	int	ret;

	ret = 0;
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (number < 0)
	{
		write (1, "-", 1);
		number = -number;
		ret = 1;
	}
	ret = ret + ft_print_base("0123456789", (unsigned long)number);
	return (ret);
}
