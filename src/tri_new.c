/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 02:34:56 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/10 22:13:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_tri			*tri_new(t_mtx *a, t_mtx *b, t_mtx *c)
{
	t_tri		*out;

	out = (t_tri *)v_alloc(sizeof(t_tri));
	out->ax = a->this[0];
	out->ay = a->this[1];
	out->az = a->this[2];
	out->aw = a->this[3];
	out->bx = b->this[0];
	out->by = b->this[1];
	out->bz = b->this[2];
	out->bw = b->this[3];
	out->cx = c->this[0];
	out->cy = c->this[1];
	out->cz = c->this[2];
	out->cw = c->this[3];
	return (out);
}
