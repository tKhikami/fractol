/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 arg_valide.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: nyrandri <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/07/11 08:20:51 by nyrandri		   #+#	  #+#			  */
/*	 Updated: 2024/07/11 08:31:09 by nyrandri		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "fractol.h"

static int	arg_valide_2(char **vector, t_data *data)
{
	if (ft_strcmp("Mandelbrot", vector[1]) == 0)
	{
		data->index = 1;
		return (0);
	}
	else if (ft_strcmp("Julia", vector[1]) == 0)
	{
		data->index = 2;
		data->c.x = 0.3;
		data->c.y = 0.5;
		return (0);
	}
	else
		return (1);
}

static int	arg_valide_3(char **vector, t_data *data)
{
	if (ft_strcmp("Julia", vector[1]) == 0)
	{
		data->index = 2;
		data->c.x = ft_double_atoi(vector[2]);
		data->c.y = data->c.x;
		return (0);
	}
	else
		return (1);
}

static int	arg_valide_4(char **vector, t_data *data)
{
	if (ft_strcmp("Julia", vector[1]) == 0)
	{
		data->index = 2;
		data->c.x = ft_double_atoi(vector[2]);
		data->c.y = ft_double_atoi(vector[3]);
		return (0);
	}
	else
		return (1);
}

int	arg_valide(int n, char **vector, t_data *data)
{
	if (n == 2)
		return (arg_valide_2(vector, data));
	else if (n == 3)
		return (arg_valide_3(vector, data));
	else if (n == 4)
		return (arg_valide_4(vector, data));
	else
		return (1);
}
