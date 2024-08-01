/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:23:02 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/12 12:17:35 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

int	comportement_key(int key, t_data *data)
{
	if (key == 65307)
		mlx_loop_end(data->ptr);
	if (key == 65450)
		render(data);
	if (key == 65361 || key == 65362 || key == 65363 || key == 65364)
		key_translation(key, data);
	return (0);
}

int	button_is_press(int button, int x, int y, t_data *data)
{
	data->hook_position.x = x;
	data->hook_position.y = y;
	if (button == 1)
		data->button1 = 1;
	else if (button == 3)
	{
		data->button3 = 1;
		data->c_move.x = x;
		data->c_move.y = y;
	}
	else if (button == 4 || button == 5)
	{
		data->ratio = RATIO;
		if (button == 5)
			data->ratio = 1 / RATIO;
		system_zoom(data);
		prototype(data, &optim_zoom);
		mlx_put_image_to_window(data->ptr, data->win, \
				data->image_front.img, 0, 0);
		update_back(data);
	}
	return (0);
}

int	button_is_release(int button, int x, int y, t_data *data)
{
	if (button == 1)
		data->button1 = 0;
	if (button == 3)
	{
		c_move_julia(x, y, data);
		data->button3 = 0;
	}
	render(data);
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	if (data->button1 == 1)
		translation(x, y, data);
	return (0);
}

void	all_event(t_data *data)
{
	mlx_key_hook(data->win, &comportement_key, data);
	mlx_hook(data->win, 17, 0, &mlx_loop_end, data->ptr);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, &button_is_press, data);
	mlx_hook(data->win, ButtonRelease, \
			ButtonReleaseMask, &button_is_release, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, &mouse_move, data);
}
