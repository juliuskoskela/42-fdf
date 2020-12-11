/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_matrix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:48:24 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/11 13:00:20 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"


t_matrix		*identity(double scl)
{
	t_matrix	*out;

	out = (t_matrix *)v_alloc(sizeof(t_matrix));
	out->mx = g_vertex(scl, 0.0, 0.0, 0.0);
	out->my = g_vertex(0.0, scl, 0.0, 0.0);
	out->mz = g_vertex(0.0, 0.0, scl, 0.0);
	out->mw = g_vertex(0.0, 0.0, 0.0, 1.0);
	return (out);
}

t_matrix		*translation(t_vertex *vtx)
{
	t_matrix	*out;

	out = identity(1);
	out->mx->w = vtx->x;
	out->my->w = vtx->y;
	out->mz->w = vtx->z;
	return (out);
}

t_matrix		*rotation_x(double angle)
{
	t_matrix	*out;

	out = identity(1);
	out->mx->x = 1;
	out->my->y = cos(angle);
	out->my->z = -sin(angle);
	out->mz->y = sin(angle);
	out->mz->z = cos(angle);
	return (out);
}

t_matrix		*rotation_y(double angle)
{
	t_matrix	*out;

	out = identity(1);
	out->mx->x = cos(angle);
	out->mz->x = sin(angle);
	out->my->y = 1;
	out->mx->z = -sin(angle);
	out->mz->z = cos(angle);
	return (out);
}

t_matrix		*rotation_z(double angle)
{
	t_matrix	*out;

	out = identity(1);
	out->mx->x = cos(angle);
	out->my->x = -sin(angle);
	out->mx->z = sin(angle);
	out->my->z = cos(angle);
	out->mz->z = 1;
	return (out);
}

t_matrix		*projection(double fov, double ratio, double near, double far)
{
	t_matrix	*out;

	out = identity(1);
	out->my->y = 1 / tan(0.5 * (fov * (PI / 180)));
	out->mx->x = out->my->y / ratio;
	out->mz->z = -1 * (-near - far) / (near - far);
	out->mz->w = -1;
	out->mz->z = (2 * near * far) / (near- far);
	out->mw->w = 0;
	return (out);
}


t_vertex		 transform(t_matrix *mtx, t_vertex vtx)
{
	t_vertex	out;
	out.x = (vtx.x * mtx->mx->x) + (vtx.y * mtx->my->x) + (vtx.z * mtx->mz->x) + (vtx.w * mtx->mw->x);
	out.y = (vtx.x * mtx->mx->y) + (vtx.y * mtx->my->y) + (vtx.z * mtx->mz->y) + (vtx.w * mtx->mw->y);
	out.z = (vtx.x * mtx->mx->z) + (vtx.y * mtx->my->z) + (vtx.z * mtx->mz->z) + (vtx.w * mtx->mw->z);
	out.w = (vtx.x * mtx->mx->w) + (vtx.y * mtx->my->w) + (vtx.z * mtx->mz->w) + (vtx.w * mtx->mw->w);
	return (out);
}