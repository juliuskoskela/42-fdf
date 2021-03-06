/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:15:56 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/21 17:16:38 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_tri		g_sort_tri_y(t_tri tri)
{
	t_tri	out;

	if (tri.a.y <= tri.b.y && tri.a.y <= tri.c.y)
	{
		out.a = tri.a;
		if (tri.b.y <= tri.c.y)
		{
			out.b = tri.b;
			out.c = tri.c;
		}
		else
		{
			out.b = tri.c;
			out.c = tri.b;
		}
	}
	if (tri.b.y <= tri.b.y && tri.b.y <= tri.c.y)
	{
		out.a = tri.b;
		if (tri.a.y <= tri.c.y)
		{
			out.b = tri.a;
			out.c = tri.c;
		}
		else
		{
			out.b = tri.c;
			out.c = tri.a;
		}
	}
	if (tri.c.y <= tri.b.y && tri.c.y <= tri.c.y)
	{
		out.a = tri.c;
		if (tri.b.y <= tri.a.y)
		{
			out.b = tri.b;
			out.c = tri.a;
		}
		else
		{
			out.b = tri.a;
			out.c = tri.b;
		}
	}
	return (out);
}

void			fill_bottom(t_world *wrld,t_vct4 v1, t_vct4 v2, t_vct4 v3)
{
	t_vct4		org;
	t_vct4		dst;
	float		slope_1;
	float		slope_2;
	float		curx1;
	float		curx2;
	int			scanline;

	slope_1 = (v2.x - v1.x) / (v2.y - v1.y);
	slope_2 = (v3.x - v1.x) / (v3.y - v1.y);
	curx1 = v1.x;
	curx2 = v1.x;
	scanline = v1.y;
	while (scanline <= (int)v2.y)
	{
		org = g_vct4(curx1, scanline, 0, 0);
		dst = g_vct4(curx2, scanline, 0, 0);
		draw_line(wrld, org, dst);
		curx1 += slope_1;
		curx2 += slope_2;
		scanline++;
	}
}

void			fill_top(t_world *wrld, t_vct4 v1, t_vct4 v2, t_vct4 v3)
{
	t_vct4		org;
	t_vct4		dst;
	float		slope_1;
	float		slope_2;
	float		curx1;
	float		curx2;
	int 		scanline;

	slope_1 = (v3.x - v1.x) / (v3.y - v1.y);
	slope_2 = (v3.x - v2.x) / (v3.y - v2.y);
	curx1 = v3.x;
	curx2 = v3.x;
	scanline = v3.y;
	while (scanline >= (int)v1.y)
	{
		org = g_vct4(curx1, scanline, 0, 0);
		dst = g_vct4(curx2, scanline, 0, 0);
		draw_line(wrld, org, dst);
		curx1 -= slope_1;
		curx2 -= slope_2;
		scanline--;
	}
}

void			draw_triangle(t_world *wrld, t_tri tri)
{
	t_vct4		v4;
	t_vct4		light;
	t_vct4		face_normal;
	double		face_ratio = 0;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	shade;

	r = 255 * face_ratio;
	g = 255 * face_ratio;
	b = 255 * face_ratio;
	shade = (r << 16) + (g << 8) + b;
	tri.a.hex = shade;
	tri.b.hex = shade;
	tri.c.hex = shade;
	light = g_vct4(200, 200, 200, 1);
	face_normal = g_cross(g_sub (tri.b, tri.a), g_sub(tri.c, tri.a));
	face_ratio = g_dot(face_normal, light);

	tri = g_sort_tri_y(tri);
	if ((int64_t)tri.b.y == (int64_t)tri.c.y)
		fill_bottom(wrld, tri.a, tri.b, tri.c);
	else if ((int64_t)tri.a.y == (int64_t)tri.b.y)
		fill_top(wrld, tri.a, tri.b, tri.c);
	else
	{
		v4 = g_vct4(tri.a.x \
		+ (tri.b.y - tri.b.y) \
		/ (tri.c.y - tri.a.y) \
		* (tri.c.x - tri.a.x) \
		, tri.b.y, \
		0, 0);
		fill_bottom(wrld, tri.a, tri.b, v4);
		fill_top(wrld, tri.a, v4, tri.c);
	}
}
