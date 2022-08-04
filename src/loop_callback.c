/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_callback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:57:45 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 03:42:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void render_buffer(t_buffer *b, void *mlx, void *win)
{
	size_t	i;

	i = 0;
	while (i < b->size)
	{
		if (b->tri[i].a.x > 0.0 && b->tri[i].a.x < RESX
		&& b->tri[i].a.y > 0.0 && b->tri[i].a.y < RESY)
		{
			draw_line(mlx, win, b->tri[i].a, b->tri[i].b);
			draw_line(mlx, win, b->tri[i].a, b->tri[i].c);
			draw_line(mlx, win, b->tri[i].b, b->tri[i].c);
		}
		i++;
	}
}

int loop_callback(t_world *w)
{
	if (w->projection == PERSPECTIVE)
	{
		w->models[0].scale = 1;
		world_from_model(w);
		view_from_world(w);
		clip_from_view(w);
		window_from_clip(w);
	}
	if (w->projection == ORTHOGRAPHIC)
	{
		w->models[0].scale = 50;
		world_from_model(w);
		view_from_world(w);
	}
	render_buffer(&w->buffer, w->mlx, w->win);
	return (0);
}
