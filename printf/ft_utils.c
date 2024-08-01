/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:18:04 by nyrandri          #+#    #+#             */
/*   Updated: 2024/05/02 12:37:43 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base(const char *str, unsigned long long number)
{
	unsigned long long	quot;
	unsigned int		rest;
	unsigned int		len;
	unsigned int		base;

	len = 0;
	base = ft_strlen(str);
	if (number != 0)
	{
		rest = number % base;
		quot = number / base;
		if (quot != 0)
			len = ft_print_base(str, quot);
		write (1, &str[rest], 1);
		len++;
	}
	else
	{
		write(1, "0", 1);
		return (1);
	}
	return (len);
}
