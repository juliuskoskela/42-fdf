/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:10:51 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/12 21:16:44 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			draw_line(void *mlx, void *win, t_vct4 v0, t_vct4 v1)
{
	t_vct4		d;
	t_vct4 		s;
	int			err;
	int			e2;

	d.x = abs(v1.x - v0.x);
	s.x = v0.x < v1.x ? 1 : -1;
	d.y = -abs(v1.y - v0.y);
	s.y = v0.y < v1.y ? 1 : -1;
	err = d.x + d.y;
	while (1)
	{
		mlx_pixel_put(mlx, win, v0.x, v0.y, 0xFFFFFF);
		if (v0.x == v1.x && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= d.y)
		{
			err += d.y;
			v0.x += s.x;
		}
		if (e2 <= d.x)
		{
			err += d.x;
			v0.y += s.y;
		}
	}
}
