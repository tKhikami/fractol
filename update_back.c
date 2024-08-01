/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:58:58 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/08 13:18:49 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

void	update_system_back(t_data *data)
{
	data->image_back.system.origine_x = data->image_front.system.origine_x;
	data->image_back.system.origine_y = data->image_front.system.origine_y;
	data->image_back.system.i = data->image_front.system.i;
	data->image_back.system.j = data->image_front.system.j;
}

void	update_back(t_data *data)
{
	int	tab[2];
	int	color;

	update_system_back(data);
	tab[0] = 0;
	while (tab[0] <= WIN_LENGTH)
	{
		tab[1] = 0;
		while (tab[1] <= WIN_WIDTH)
		{
			color = get_color_pixel(&data->image_front, tab[1], tab[0]);
			my_mlx_pixel_put(&data->image_back, tab[1], tab[0], color);
			tab[1]++;
		}
		tab[0]++;
	}
}
