/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:26:21 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/30 11:16:43 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

int	main(int n, char *vector[])
{
	t_data	data;

	if (arg_valide(n, vector, &data) == 1)
	{
		return (error_message(), 0);
	}
	else
	{
		if (init_all(&data, "test") == 1)
			return (1);
		all_event(&data);
	}
	mlx_loop(data.ptr);
	mlx_destroy_window(data.ptr, data.win);
	mlx_destroy_image(data.ptr, data.image_front.img);
	mlx_destroy_image(data.ptr, data.image_back.img);
	mlx_destroy_display(data.ptr);
	free(data.ptr);
	return (0);
}
