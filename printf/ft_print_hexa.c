/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:59:50 by nyrandri          #+#    #+#             */
/*   Updated: 2024/05/02 09:35:15 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int number, int c)
{
	if (c == 'x')
		return (ft_print_base("0123456789abcdef", number));
	else
		return (ft_print_base("0123456789ABCDEF", number));
}
