/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_from_clip.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:58:46 by jkoskela          #+#    #+#             */
/*   Updated: 2021/03/09 16:07:55 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static t_vct4	pers_div(t_vct4 v_c)
{
	t_vct4		v_d;

	v_d.x = v_c.x / v_c.w;
	v_d.y = v_c.y / v_c.w;
	v_d.z = v_c.z / v_c.w;
	v_d.w = v_c.w / v_c.w;
	return (v_d);
}

static t_vct4	win_stretch(t_vct4 v_d)
{
	t_vct4		v_s;

	v_s.x = (RESX * (v_d.x + 1)) / 2 + SCREEN_OFFSET_X;
	v_s.y = (RESY * (v_d.y + 1)) / 2 + SCREEN_OFFSET_Y;
	v_s.z = v_s.z;
	v_s.w = v_d.w;
	return (v_s);
}

size_t			window_from_clip(t_world *wld)
{
	size_t		i;

	i = 0;
	while (i < wld->buffer.size)
	{
		if (wld->buffer.tri[i].a.w != 0 &&
			wld->buffer.tri[i].b.w != 0 &&
			wld->buffer.tri[i].c.w != 0)
		{
			wld->buffer.tri[i].a = win_stretch(pers_div(wld->buffer.tri[i].a));
			wld->buffer.tri[i].b = win_stretch(pers_div(wld->buffer.tri[i].b));
			wld->buffer.tri[i].c = win_stretch(pers_div(wld->buffer.tri[i].c));
		}
		i++;
	}
	if (g_verbose > 0)
		printf("SUCCESS: %zu clip vertices converted to device space!\n", i);
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	WINDOW_FROM_CLIP
**
**	! This is actually two steps combines. It does perspective division and
**	then stretches the x and y coordinates to the window.
**
**  ----------------------------------------------------------------------------
*/
