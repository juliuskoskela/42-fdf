/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rot_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:19:33 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:04:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

t_matrix		*mtx_rot_z(double angle)
{
	t_matrix	*out;

	out = (t_matrix *)v_alloc(sizeof(t_matrix));
	out->mx = g_vertex(1.0, 0.0, 0.0, 0.0);
	out->my = g_vertex(0.0, 1.0, 0.0, 0.0);
	out->mz = g_vertex(0.0, 0.0, 1.0, 0.0);
	out->mw = g_vertex(0.0, 0.0, 0.0, 1.0);
	out->mx->x = cos(angle);
	out->my->x = -sin(angle);
	out->mx->z = sin(angle);
	out->my->z = cos(angle);
	out->mz->z = 1;
	return (out);
}
