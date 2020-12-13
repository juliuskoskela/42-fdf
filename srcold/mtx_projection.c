/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:19:54 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:04:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

t_matrix		*mtx_projection(double fov, double ratio, double near, double far)
{
	t_matrix	*out;

	out = (t_matrix *)v_alloc(sizeof(t_matrix));
	out->mx = g_vertex(1.0, 0.0, 0.0, 0.0);
	out->my = g_vertex(0.0, 1.0, 0.0, 0.0);
	out->mz = g_vertex(0.0, 0.0, 1.0, 0.0);
	out->mw = g_vertex(0.0, 0.0, 0.0, 1.0);
	out->my->y = 1 / tan(0.5 * (fov * (PI / 180)));
	out->mx->x = out->my->y / ratio;
	out->mz->z = -1 * (-near - far) / (near - far);
	out->mz->w = -1;
	out->mz->z = (2 * near * far) / (near- far);
	out->mw->w = 0;
	return (out);
}
