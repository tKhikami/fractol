/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:27:19 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/11 09:06:33 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

static void	init_some_stuff(t_data *data)
{
	data->image_front.addr = mlx_get_data_addr(data->image_front.img, \
			&data->image_front.bpp, &data->image_front.line_len, \
			&data->image_front.endian);
	data->image_back.addr = mlx_get_data_addr(data->image_back.img, \
			&data->image_back.bpp, &data->image_back.line_len, \
			&data->image_back.endian);
	default_system(&data->image_front.system);
	data->button1 = 0;
	data->button3 = 0;
	data->color = 0xff00ff00;
	render(data);
}

int	init_all(t_data *data, char *str)
{
	data->ptr = mlx_init();
	if (data->ptr == NULL)
		return (1);
	data->win = mlx_new_window(data->ptr, WIN_WIDTH, WIN_LENGTH, str);
	if (data->win == NULL)
		return (mlx_destroy_display(data->ptr), free(data->ptr), 1);
	data->image_front.img = mlx_new_image(data->ptr, WIN_WIDTH, WIN_LENGTH);
	if (data->image_front.img == NULL)
	{
		mlx_destroy_window(data->ptr, data->win);
		return (mlx_destroy_display(data->ptr), free(data->ptr), 1);
	}
	data->image_back.img = mlx_new_image(data->ptr, WIN_WIDTH, WIN_LENGTH);
	if (data->image_back.img == NULL)
	{
		mlx_destroy_image(data->ptr, data->image_front.img);
		mlx_destroy_window(data->ptr, data->win);
		return (mlx_destroy_display(data->ptr), free(data->ptr), 1);
	}
	init_some_stuff(data);
	return (0);
}
