/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:57:45 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 23:29:57 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		render_tri(void *mlx, void *win, t_tri *tri)
{
	mlx_pixel_put(mlx, win, tri->a.x, tri->a.y, 0xFFFFFF);
	mlx_pixel_put(mlx, win, tri->b.x, tri->b.y, 0xFFFFFF);
	mlx_pixel_put(mlx, win, tri->c.x, tri->c.y, 0xFFFFFF);
	draw_line(mlx, win, tri->a, tri->b);
	draw_line(mlx, win, tri->a, tri->c);
}

void			render(t_world wrld)
{
	size_t		i;

	i = 0;
	while (i < wrld.tri_cnt)
	{
		render_tri(wrld.mlx_ptr, wrld.win_ptr, &wrld.buffer[i]);
		// draw_triangle(wrld.mlx_ptr, wrld.win_ptr, wrld.buffer[i]);
		i++;
	}
	mlx_key_hook(wrld.win_ptr, key_callback, &wrld);
	mlx_loop(wrld.mlx_ptr);
}
