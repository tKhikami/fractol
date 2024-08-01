/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:08:08 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/31 22:21:52 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

double	blue_shade(t_coordonne next, double i)
{
	double	ret;

	ret = (i - log2(fmax(2, log2(next.x * next.x + next.y * next.y) / 4))) * 5;
	return (ret);
}

void	mandelbrot(int *tab, t_data *data)
{
	t_coordonne	c;
	t_coordonne	next;
	int			i;
	double		temp;

	i = 0;
	next.x = 0;
	next.y = 0;
	c = pixel_to_affine(tab[0], tab[1], data->image_front.system);
	while (i++ < ACCURACY && next.x * next.x + next.y * next.y <= 4)
	{
		temp = (next.x * next.x) - (next.y * next.y) + c.x;
		next.y = (2 * next.x * next.y) + c.y;
		next.x = temp;
	}
	if (next.x * next.x + next.y * next.y <= 4)
		my_mlx_pixel_put(&(data->image_front), tab[1], tab[0], data->color);
	else
		my_mlx_pixel_put(&(data->image_front), \
				tab[1], tab[0], blue_shade(next, i));
}
