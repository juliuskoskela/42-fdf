/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:52:51 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 20:02:30 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		plot4points(void *mlx, void *win, int cx, int cy, int x, int y)
{
	mlx_pixel_put(mlx, win, cx + x, cy + y, 0xFFFFFF);
	if (x != 0)
		mlx_pixel_put(mlx, win, cx - x, cy + y, 0xFFFFFF);
	if (y != 0)
		mlx_pixel_put(mlx, win, cx + x, cy - y, 0xFFFFFF);
	if (x != 0 && y != 0)
		mlx_pixel_put(mlx, win, cx - x, cy - y, 0xFFFFFF);
}

static void		plot8points(void *mlx, void *win, int cx, int cy, int x, int y)
{
	plot4points (win, mlx, cx, cy, x, y);
	if (x != y) plot4points (win, mlx, cx, cy, y, x);
}

void		draw_circle(void *mlx, void *win, t_vct4 offset, int radius)
{
	int		error;
	int		x;
	int		y;

	error = -radius;
	x = radius;
	y = 0;
	while (x >= y)
	{
		plot8points(win, mlx, offset.x, offset.y, x, y);
		error += y;
		++y;
		error += y;
		if (error >= 0)
		{
			--x;
			error -= x;
			error -= x;
		}
	}
}
