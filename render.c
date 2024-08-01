/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:48:50 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/10 13:27:43 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

static void	render_mandelbrot(t_data *data)
{
	prototype(data, &mandelbrot);
	mlx_put_image_to_window(data->ptr, data->win, data->image_front.img, 0, 0);
	update_back(data);
}

static void	render_julia(t_data *data)
{
	prototype(data, &julia);
	mlx_put_image_to_window(data->ptr, data->win, data->image_front.img, 0, 0);
	update_back(data);
}

void	render(t_data *data)
{
	if (data->index == 1)
	{
		render_mandelbrot(data);
	}
	if (data->index == 2)
	{
		render_julia(data);
	}
}
