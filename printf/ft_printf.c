/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:23:10 by nyrandri          #+#    #+#             */
/*   Updated: 2024/05/02 12:37:08 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_condition(int c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_print_array((unsigned long)va_arg(arg, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_integer(va_arg(arg, int)));
	if (c == 'u')
		return (ft_print_positif_integer(va_arg(arg, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_print_hexa(va_arg(arg, unsigned int), c));
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			ret++;
		}
		else
		{
			i++;
			ret = ret + ft_condition(str[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (ret);
}
