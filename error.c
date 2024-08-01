/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:16:36 by nyrandri          #+#    #+#             */
/*   Updated: 2024/08/01 08:00:43 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(void)
{
	ft_printf("\n ===========================================\n");
	ft_printf(" |  ARG_ERROR!!                             |\n");
	ft_printf(" |  fractol avalaible are :                 |\n");
	ft_printf(" |\t-Mandelbrot                         |\n");
	ft_printf(" |\t-Julia 'a' 'b'(z = a + ib optinal)  |\n");
	ft_printf(" ===========================================\n");
}

static int	sign(int *i, char *str)
{
	int	ret;

	if (str[*i] == '-')
	{
		*i = 1;
		ret = -1;
	}
	else if (str[*i] == '+')
	{
		*i = 1;
		ret = 1;
	}
	else
	{
		*i = 0;
		ret = 1;
	}
	return (ret);
}

double	ft_double_atoi(char *str)
{
	double	ret;
	int		i;
	int		s;
	int		pow;

	ret = 0;
	i = 0;
	pow = 0;
	s = sign(&i, str);
	while (str[i] >= '0' && str[i] <= '9')
		ret = (ret * 10) + str[i++] - '0';
	if (str[i++] == '.')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			ret = (ret * 10) + str[i++] - '0';
			pow++;
		}
	}
	while (pow != 0)
	{
		ret /= 10;
		pow--;
	}
	return (s * ret);
}
