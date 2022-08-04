/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_from_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:57:02 by jkoskela          #+#    #+#             */
/*   Updated: 2021/03/08 18:23:58 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int		clip_tri(t_tri tri)
{
	if (tri.a.w >= 0.0)
		return (1);
	else if (tri.b.w >= 0.0)
		return (1);
	else if (tri.c.w >= 0.0)
		return (1);
	return (0);
}

size_t			clip_from_view(t_world *wld)
{
	t_mtx4		m;
	size_t		i;
	size_t		j;

	m = g_proj(wld->a_cam.fov, wld->a_cam.ratio, \
	wld->a_cam.near, wld->a_cam.far);
	process_buffer(&wld->buffer, m);
	i = 0;
	j = 0;
	while (i < wld->buffer.size)
	{
		if (wld->buffer.size == 0)
			return (0);
		else if (clip_tri(wld->buffer.tri[i]))
			wld->buffer.size--;
		else
		{
			wld->buffer.tri[j] = wld->buffer.tri[i];
			j++;
		}
		i++;
	}
	if (g_verbose > 0)
		printf("SUCCESS: %zu view vertices converted to clip space!\n", i);
	return (i);
}
