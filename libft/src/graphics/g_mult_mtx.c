/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mult_mtx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:28:34 by jkoskela          #+#    #+#             */
/*   Updated: 2021/03/08 21:10:48 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static t_mtx4	g_mult_mtx1(t_mtx4 a, t_mtx4 b, t_mtx4 c)
{
	c.v1.x = a.v1.x * b.v1.x + a.v1.y *
	b.v2.x + a.v1.z * b.v3.x + a.v1.w * b.v4.x;
	c.v1.y = a.v1.x * b.v1.y + a.v1.y *
	b.v2.y + a.v1.z * b.v3.y + a.v1.w * b.v4.y;
	c.v1.z = a.v1.x * b.v1.z + a.v1.y *
	b.v2.z + a.v1.z * b.v3.z + a.v1.w * b.v4.z;
	c.v1.w = a.v1.x * b.v1.w + a.v1.y *
	b.v2.w + a.v1.z * b.v3.w + a.v1.w * b.v4.w;
	c.v2.x = a.v2.x * b.v1.x + a.v2.y *
	b.v2.x + a.v2.z * b.v3.x + a.v2.w * b.v4.x;
	c.v2.y = a.v2.x * b.v1.y + a.v2.y *
	b.v2.y + a.v2.z * b.v3.y + a.v2.w * b.v4.y;
	c.v2.z = a.v2.x * b.v1.z + a.v2.y *
	b.v2.z + a.v2.z * b.v3.z + a.v2.w * b.v4.z;
	c.v2.w = a.v2.x * b.v1.w + a.v2.y *
	b.v2.w + a.v2.z * b.v3.w + a.v2.w * b.v4.w;
	return (c);
}

static t_mtx4	g_mult_mtx2(t_mtx4 a, t_mtx4 b, t_mtx4 c)
{
	c.v3.x = a.v3.x * b.v1.x + a.v3.y *
	b.v2.x + a.v3.z * b.v3.x + a.v3.w * b.v4.x;
	c.v3.y = a.v3.x * b.v1.y + a.v3.y *
	b.v2.y + a.v3.z * b.v3.y + a.v3.w * b.v4.y;
	c.v3.z = a.v3.x * b.v1.z + a.v3.y *
	b.v2.z + a.v3.z * b.v3.z + a.v3.w * b.v4.z;
	c.v3.w = a.v3.x * b.v1.w + a.v3.y *
	b.v2.w + a.v3.z * b.v3.w + a.v3.w * b.v4.w;
	c.v4.x = a.v4.x * b.v1.x + a.v4.y *
	b.v2.x + a.v4.z * b.v3.x + a.v4.w * b.v4.x;
	c.v4.y = a.v4.x * b.v1.y + a.v4.y *
	b.v2.y + a.v4.z * b.v3.y + a.v4.w * b.v4.y;
	c.v4.z = a.v4.x * b.v1.z + a.v4.y *
	b.v2.z + a.v4.z * b.v3.z + a.v4.w * b.v4.z;
	c.v4.w = a.v4.x * b.v1.w + a.v4.y *
	b.v2.w + a.v4.z * b.v3.w + a.v4.w * b.v4.w;
	return (c);
}

t_mtx4			g_mult_mtx(t_mtx4 a, t_mtx4 b)
{
	t_mtx4		c;

	c = g_mult_mtx1(a, b, c);
	c = g_mult_mtx2(a, b, c);
	return (c);
}

/*
**  ----------------------------------------------------------------------------
**
**	G_mult_mtx
**
**	Multiply matrix `a` by matrix `b`.
**
**  ----------------------------------------------------------------------------
*/
