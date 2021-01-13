/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:55:33 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 21:57:20 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"

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

void			fill_bottom(void *mlx, void *win,t_vct4 v1, t_vct4 v2, t_vct4 v3)
{
	t_vct4		org;
	t_vct4		dst;
	float		invslope1;
	float		invslope2;
	float		curx1;
	float		curx2;
	int			scanlineY;

	invslope1 = (v2.x - v1.x) / (v2.y - v1.y);
	invslope2 = (v3.x - v1.x) / (v3.y - v1.y);
	curx1 = v1.x;
	curx2 = v1.x;
	scanlineY = v1.y;
	while (scanlineY <= v2.y)
	{
		org = g_vct4((int)curx1, scanlineY, 0, 0);
		dst = g_vct4((int)curx2, scanlineY, 0, 0);
		draw_line(mlx, win, org, dst);
		curx1 += invslope1;
		curx2 += invslope2;
		scanlineY++;
	}
}

void			fill_top(void *mlx, void *win, t_vct4 v1, t_vct4 v2, t_vct4 v3)
{
	t_vct4		org;
	t_vct4		dst;
	float		invslope1;
	float		invslope2;
	float		curx1;
	float		curx2;
	int 		scanlineY;

	invslope1 = (v3.x - v1.x) / (v3.y - v1.y);
	invslope2 = (v3.x - v2.x) / (v3.y - v2.y);
	curx1 = v3.x;
	curx2 = v3.x;
	scanlineY = v3.y;
	while (scanlineY > v1.y)
	{
		org = g_vct4((int)curx1, scanlineY, 0, 0);
		dst = g_vct4((int)curx2, scanlineY, 0, 0);
		draw_line(mlx, win, org, dst);
		curx1 -= invslope1;
		curx2 -= invslope2;
		scanlineY--;
	}
}

void			draw_triangle(void *mlx, void *win, t_tri tri)
{
	t_vct4		v4;
	t_tri		bottom;
	t_tri		up;

	tri = g_sort_tri_y(tri);
	if ((int64_t)tri.b.y == (int64_t)tri.c.y)
		fill_bottom(mlx, win, tri.a, tri.b, tri.c);
	else if ((int64_t)tri.a.y == (int64_t)tri.b.y)
		fill_top(mlx, win, tri.a, tri.b, tri.c);
	else
	{
		v4 = g_vct4( \
		(int64_t)(tri.a.x \
		+ ((float)(tri.b.y - tri.b.y)
		/ (float)(tri.c.y - tri.a.y))
		* (tri.c.x - tri.a.x)), tri.b.y, 0, 0);
		fill_bottom(mlx, win, tri.a, tri.b, v4);
		fill_top(mlx, win, tri.a, v4, tri.c);
	}
}

int			main(void)
{
	t_tri	abc;
	t_tri	ret;

	abc.a = g_vct4(2, 5, 0, 0);
	abc.b = g_vct4(3, 7, 0, 0);
	abc.c = g_vct4(1, 4, 0, 0);

	ret = g_sort_tri_y(abc);

	g_print_vct(ret.a, 1);
	g_print_vct(ret.b, 2);
	g_print_vct(ret.c, 3);

	return (0);
}
