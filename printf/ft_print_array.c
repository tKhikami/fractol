/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:06:24 by nyrandri          #+#    #+#             */
/*   Updated: 2024/05/02 08:07:55 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_array(unsigned long number)
{
	char	mark[2];
	int		ret;

	mark[0] = '0';
	mark[1] = 'x';
	if (number == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, mark, 2);
	ret = ft_print_base("0123456789abcdef", number);
	return (ret + 2);
}
