/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 08:59:34 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/10 13:45:01 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*index;

	index = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int *)index = color;
}

int	get_color_pixel(t_image *image, int x, int y)
{
	char	*index;

	index = image->addr + (y * image->line_len + x * (image-> bpp / 8));
	return (*(int *)index);
}
