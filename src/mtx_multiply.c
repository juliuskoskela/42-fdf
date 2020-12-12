/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_multiply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:45:00 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/12 16:43:41 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_matrix		*mtx_multiply(t_matrix *a, t_matrix *b)
{
	t_matrix	*out;

	out = (t_matrix *)v_alloc(sizeof(t_matrix));
	out->mx = (t_vertex *)v_alloc(sizeof(t_vertex));
	out->my = (t_vertex *)v_alloc(sizeof(t_vertex));
	out->mz = (t_vertex *)v_alloc(sizeof(t_vertex));
	out->mw = (t_vertex *)v_alloc(sizeof(t_vertex));

	out->mx->x = (a->mx->x * b->mx->x) + (a->mx->y * b->my->x) + (a->mx->z * b->mz->x) + (a->mx->w * b->mw->x);
	out->my->x = (a->mx->x * b->mx->y) + (a->mx->y * b->my->y) + (a->mx->z * b->mz->y) + (a->mx->w * b->mw->y);
	out->mz->x = (a->mx->x * b->mx->z) + (a->mx->y * b->my->z) + (a->mx->z * b->mz->z) + (a->mx->w * b->mw->z);
	out->mw->x = (a->mx->x * b->mx->w) + (a->mx->y * b->my->w) + (a->mx->z * b->mz->w) + (a->mx->w * b->mw->w);

	out->mx->y = (a->my->x * b->mx->x) + (a->my->y * b->my->x) + (a->my->z * b->mz->x) + (a->my->w * b->mw->x);
	out->my->y = (a->my->x * b->mx->y) + (a->my->y * b->my->y) + (a->my->z * b->mz->y) + (a->my->w * b->mw->y);
	out->mz->y = (a->my->x * b->mx->z) + (a->my->y * b->my->z) + (a->my->z * b->mz->z) + (a->my->w * b->mw->z);
	out->mw->y = (a->my->x * b->mx->w) + (a->my->y * b->my->w) + (a->my->z * b->mz->w) + (a->my->w * b->mw->w);

	out->mx->z = (a->mz->x * b->mx->x) + (a->mz->y * b->my->x) + (a->mz->z * b->mz->x) + (a->mz->w * b->mw->x);
	out->my->z = (a->mz->x * b->mx->y) + (a->mz->y * b->my->y) + (a->mz->z * b->mz->y) + (a->mz->w * b->mw->y);
	out->mz->z = (a->mz->x * b->mx->z) + (a->mz->y * b->my->z) + (a->mz->z * b->mz->z) + (a->mz->w * b->mw->z);
	out->mw->z = (a->mz->x * b->mx->w) + (a->mz->y * b->my->w) + (a->mz->z * b->mz->w) + (a->mz->w * b->mw->w);

	out->mx->w = (a->mw->x * b->mx->x) + (a->mw->y * b->my->x) + (a->mw->z * b->mz->x) + (a->mw->w * b->mw->x);
	out->my->w = (a->mw->x * b->mx->y) + (a->mw->y * b->my->y) + (a->mw->z * b->mz->y) + (a->mw->w * b->mw->y);
	out->mz->w = (a->mw->x * b->mx->z) + (a->mw->y * b->my->z) + (a->mw->z * b->mz->z) + (a->mw->w * b->mw->z);
	out->mw->w = (a->mw->x * b->mx->w) + (a->mw->y * b->my->w) + (a->mw->z * b->mz->w) + (a->mw->w * b->mw->w);

	return (out);
}
