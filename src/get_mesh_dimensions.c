/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mesh_dimensions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:26:59 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 03:42:08 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static double get_width(t_vct4 *shape, size_t size)
{
	size_t	i;
	double	out;

	i = 0;
	out = 0;
	while (i < size)
	{
		if (out < shape[i].x)
			out = shape[i].x;
		i++;
	}
	return (out);
}

static double get_height(t_vct4 *shape, size_t size)
{
	size_t	i;
	double	out;

	i = 0;
	out = 0;
	while (i < size)
	{
		if (out < m_fabs(shape[i].y))
			out = m_fabs(shape[i].y);
		i++;
	}
	return (out);
}

static double get_depth(t_vct4 *shape, size_t size)
{
	size_t	i;
	double	out;

	i = 0;
	out = 0;
	while (i < size)
	{
		if (out < shape[i].z)
			out = shape[i].z;
		i++;
	}
	return (out);
}

t_vct4 get_mesh_dimensions(t_vct4 *shape, size_t size)
{
	t_vct4	out;

	out.x = get_width(shape, size) + 1;
	out.y = get_height(shape, size) + 1;
	out.z = get_depth(shape, size) + 1;
	out.w = 1;
	return (out);
}
