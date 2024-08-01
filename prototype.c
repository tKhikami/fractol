/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:29:14 by nyrandri          #+#    #+#             */
/*   Updated: 2024/07/10 11:19:27 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

void	prototype(t_data *data, void (*f)())
{
	int	tab[2];

	tab[0] = 0;
	while (tab[0] <= WIN_LENGTH)
	{
		tab[1] = 0;
		while (tab[1] <= WIN_WIDTH)
		{
			(*f)(tab, data);
			tab[1]++;
		}
		tab[0]++;
	}
}
