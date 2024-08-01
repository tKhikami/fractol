/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:43:36 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/12 12:17:13 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

int	translation(int x, int y, t_data *data)
{
	t_coordonne	vector;

	vector.x = x - data->hook_position.x;
	vector.y = y - data->hook_position.y;
	data->hook_position.x = x;
	data->hook_position.y = y;
	if (data->index == 1)
		pixel_translation(data, vector, &mandelbrot);
	else if (data->index == 2)
		pixel_translation(data, vector, &julia);
	mlx_put_image_to_window(data->ptr, data->win, data->image_front.img, 0, 0);
	update_back(data);
	return (0);
}

int	key_translation(int key, t_data *data)
{
	t_coordonne	vector;

	vector.x = 0;
	vector.y = 0;
	if (key == 65361)
		vector.x = -10;
	if (key == 65362)
		vector.y = -10;
	if (key == 65363)
		vector.x = 10;
	if (key == 65364)
		vector.y = 10;
	if (data->index == 1)
		pixel_translation(data, vector, &mandelbrot);
	else if (data->index == 2)
		pixel_translation(data, vector, &julia);
	mlx_put_image_to_window(data->ptr, data->win, data->image_front.img, 0, 0);
	update_back(data);
	return (0);
}

void	pixel_translation(t_data *data, \
		t_coordonne vector, void (*f)())
{
	int	tab[2];
	int	temp[2];

	data->image_front.system.origine_x += vector.x;
	data->image_front.system.origine_y += vector.y;
	tab[0] = 0;
	while (tab[0] <= WIN_LENGTH)
	{
		tab[1] = 0;
		while (tab[1] <= WIN_WIDTH)
		{
			temp[1] = tab[1] - vector.x;
			temp[0] = tab[0] - vector.y;
			if (temp[1] > 0 && temp[1] < WIN_WIDTH && \
					temp[0] > 0 && temp[0] < WIN_LENGTH)
				my_mlx_pixel_put(&data->image_front, tab[1], tab[0], \
						get_color_pixel(&data->image_back, temp[1], temp[0]));
			else
				(*f)(tab, data);
			tab[1]++;
		}
		tab[0]++;
	}
}
