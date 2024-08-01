/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homothety.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:53:13 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/10 14:36:54 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

t_coordonne	homothety(t_coordonne point, t_coordonne center, double ratio)
{
	t_coordonne	ret;

	ret.x = ratio * (point.x - center.x) + center.x;
	ret.y = ratio * (point.y - center.y) + center.y;
	return (ret);
}
