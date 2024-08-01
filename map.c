/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:55:19 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/11 09:02:55 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

void	default_system(t_sys *system)
{
	system->origine_x = WIN_WIDTH / 2;
	system->origine_y = WIN_LENGTH / 2;
	system->i = min(WIN_LENGTH / 5, WIN_WIDTH / 5);
	system->j = min(WIN_LENGTH / 5, WIN_WIDTH / 5);
}

t_coordonne	pixel_to_affine(double a, double b, t_sys system)
{
	t_coordonne	value;

	value.x = (a - (double)(system.origine_y)) / (double)system.i;
	value.y = (b - (double)(system.origine_x)) / (double)system.j;
	return (value);
}

void	affine_to_pixel(int *i, int *j, t_coordonne pos, t_sys system)
{
	*i = (pos.x * system.i) + system.origine_y;
	*j = (pos.y * system.j) + system.origine_x;
}
