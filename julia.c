/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:09:56 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/11 11:55:45 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

int	c_move_julia(int x, int y, t_data *data)
{
	t_coordonne	temp1;
	t_coordonne	temp2;

	temp1 = pixel_to_affine(x, y, data->image_front.system);
	temp2 = pixel_to_affine(data->c_move.x, data->c_move.y, \
			data->image_front.system);
	data->c.x += (temp1.x - temp2.x) / 10;
	data->c.y += (temp1.y - temp2.y) / 10;
	render(data);
	return (0);
}

void	julia(int *tab, t_data *data)
{
	t_coordonne	next;
	int			i;
	double		temp;

	i = 0;
	next = pixel_to_affine(tab[0], tab[1], data->image_front.system);
	while (i++ < ACCURACY && next.x * next.x + next.y * next.y <= 4)
	{
		temp = (next.x * next.x) - (next.y * next.y) + data->c.x;
		next.y = (2 * next.x * next.y) + data->c.y;
		next.x = temp;
	}
	if (next.x * next.x + next.y * next.y <= 4)
		my_mlx_pixel_put(&(data->image_front), tab[1], tab[0], data->color);
	else
		my_mlx_pixel_put(&(data->image_front), \
				tab[1], tab[0], blue_shade(next, i));
}
