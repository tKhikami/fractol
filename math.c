/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:07:08 by nyrandri          #+#    #+#             */
/*   Updated: 2024/06/25 12:46:58 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coordonne	produit(t_coordonne a, t_coordonne b)
{
	t_coordonne	ret;

	ret.x = (a.x * b.x) - (a.y * b.y);
	ret.y = (a.y * b.x) + (b.y * a.x);
	return (ret);
}

double	norme(t_coordonne a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2)));
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
