/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:15:21 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/11 07:03:07 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

void	system_zoom(t_data *data)
{
	t_coordonne	temp;
	t_coordonne	new_origine;

	temp.x = data->image_front.system.origine_x;
	temp.y = data->image_front.system.origine_y;
	new_origine = homothety(temp, data->hook_position, data->ratio);
	data->image_front.system.origine_x = new_origine.x;
	data->image_front.system.origine_y = new_origine.y;
	data->image_front.system.i *= data->ratio;
	data->image_front.system.j *= data->ratio;
}
