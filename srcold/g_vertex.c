/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vertex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:41:08 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:04:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

t_vertex		*g_vertex(double x, double y, double z, double w)
{
	t_vertex	*out;

	out = (t_vertex *)v_alloc(sizeof(t_vertex));
	out->x = x;
	out->y = y;
	out->z = z;
	out->w = w;
	return (out);
}
