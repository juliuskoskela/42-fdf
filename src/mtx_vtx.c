/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_vtx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:20:42 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/12 04:20:50 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vertex		 mtx_vtx(t_matrix *mtx, t_vertex vtx)
{
	t_vertex	out;
	out.x = (vtx.x * mtx->mx->x) + (vtx.y * mtx->my->x) + (vtx.z * mtx->mz->x) + (vtx.w * mtx->mw->x);
	out.y = (vtx.x * mtx->mx->y) + (vtx.y * mtx->my->y) + (vtx.z * mtx->mz->y) + (vtx.w * mtx->mw->y);
	out.z = (vtx.x * mtx->mx->z) + (vtx.y * mtx->my->z) + (vtx.z * mtx->mz->z) + (vtx.w * mtx->mw->z);
	out.w = (vtx.x * mtx->mx->w) + (vtx.y * mtx->my->w) + (vtx.z * mtx->mz->w) + (vtx.w * mtx->mw->w);
	return (out);
}
