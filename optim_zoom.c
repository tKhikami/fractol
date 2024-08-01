/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optim_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:21:40 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/11 08:50:59 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

int	check(int color, t_data *data, t_coordonne temp)
{
	int	var[8];
	int	i;

	i = 0;
	var[0] = get_color_pixel(&data->image_back, temp.x - 1, temp.y - 1);
	var[1] = get_color_pixel(&data->image_back, temp.x - 1, temp.y);
	var[2] = get_color_pixel(&data->image_back, temp.x - 1, temp.y + 1);
	var[3] = get_color_pixel(&data->image_back, temp.x, temp.y - 1);
	var[4] = get_color_pixel(&data->image_back, temp.x, temp.y + 1);
	var[5] = get_color_pixel(&data->image_back, temp.x + 1, temp.y);
	var[6] = get_color_pixel(&data->image_back, temp.x + 1, temp.y - 1);
	var[7] = get_color_pixel(&data->image_back, temp.x + 1, temp.y + 1);
	while (i < 8)
	{
		if (color != var[i])
			return (0);
		i++;
	}
	return (1);
}

void	optim_zoom(int *tab, t_data *data)
{
	t_coordonne	temp;
	t_coordonne	current;
	int			color;

	current.x = tab[1];
	current.y = tab[0];
	temp = homothety(current, data->hook_position, 1 / data->ratio);
	if (temp.x > 0 && temp.x < WIN_WIDTH && \
			temp.y > 0 && temp.y < WIN_LENGTH)
	{
		color = get_color_pixel(&data->image_back, temp.x, temp.y);
		if (check(color, data, temp) == 1)
		{
			my_mlx_pixel_put(&data->image_front, \
					current.x, current.y, color);
			return ;
		}
	}
	if (data->index == 1)
		mandelbrot(tab, data);
	else if (data->index == 2)
		julia(tab, data);
}

void	zoom(int button, t_data *data)
{
	data->ratio = RATIO;
	if (button == 5)
		data->ratio = 1 / RATIO;
	system_zoom(data);
	prototype(data, &optim_zoom);
	mlx_put_image_to_window(data->ptr, data->win, data->image_front.img, 0, 0);
	update_back(data);
}
