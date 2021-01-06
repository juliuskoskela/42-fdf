/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:57:45 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 06:36:02 by jkoskela         ###   ########.fr       */
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

void			render(t_world *wrld)
{
	t_dlist		*tmp;
	t_tri		*cast;

	tmp = wrld->wrld_tri_buff;
	while (tmp)
	{
		cast = tmp->content;
		mlx_pixel_put(wrld->mlx_ptr, wrld->win_ptr, \
		cast->v1->this[0], cast->v1->this[1], 0xFFFFFF);
		mlx_pixel_put(wrld->mlx_ptr, wrld->win_ptr, \
		cast->v2->this[0], cast->v2->this[1], 0xFFFFFF);
		mlx_pixel_put(wrld->mlx_ptr, wrld->win_ptr, \
		cast->v3->this[0], cast->v3->this[1], 0xFFFFFF);
		plot_line(wrld->mlx_ptr, wrld->win_ptr, \
		cast->v1->this[0], cast->v1->this[1], \
		cast->v2->this[0], cast->v2->this[1]);
		plot_line(wrld->mlx_ptr, wrld->win_ptr, \
		cast->v1->this[0], cast->v1->this[1], \
		cast->v3->this[0], cast->v3->this[1]);
		tmp = tmp->next;
	}
}
