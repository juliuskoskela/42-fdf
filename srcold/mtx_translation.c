/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_translation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:18:29 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:04:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

t_matrix		*mtx_translation(t_vertex *vtx)
{
	t_matrix	*out;

	out = (t_matrix *)v_alloc(sizeof(t_matrix));
	out->mx = g_vertex(1.0, 0.0, 0.0, 0.0);
	out->my = g_vertex(0.0, 1.0, 0.0, 0.0);
	out->mz = g_vertex(0.0, 0.0, 1.0, 0.0);
	out->mw = g_vertex(0.0, 0.0, 0.0, 1.0);
	out->mw->x = vtx->x;
	out->mw->y = vtx->y;
	out->mw->z = vtx->z;
	out->mw->w = vtx->w;
	return (out);
}
