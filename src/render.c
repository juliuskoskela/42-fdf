/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:57:45 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/12 17:32:03 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			plot_line(void *mlx, void *win, int x0, int y0, int x1, int y1)
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;

	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		mlx_pixel_put(mlx, win, x0, y0, 0xFFFFFF);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void			print_tri(t_tri tri, int i)
{
	g_print_vct(tri.a, i);
	g_print_vct(tri.b, i);
	g_print_vct(tri.c, i);
}

void			render(t_tri *buff, void *mlx, void *win, size_t size)
{
	size_t		i;


	i = 0;
	while (i < size)
	{
		mlx_pixel_put(mlx, win, buff[i].a.x, buff[i].a.y, 0xFFFFFF);
		mlx_pixel_put(mlx, win, buff[i].b.x, buff[i].b.y, 0xFFFFFF);
		mlx_pixel_put(mlx, win, buff[i].c.x, buff[i].c.y, 0xFFFFFF);
		// print_tri(buff[i], i);
		// printf("\n");
		plot_line(mlx, win, buff[i].a.x, buff[i].a.y, buff[i].b.x, buff[i].b.y);
		plot_line(mlx, win, buff[i].a.x, buff[i].a.y, buff[i].c.x, buff[i].c.y);
		i++;
	}
}
