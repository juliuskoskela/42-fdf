/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 03:33:43 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 05:55:32 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_object		*construct_object(int verbose)
{
	t_object	*out;

	out = (t_object *)v_alloc(sizeof(t_object));
	out->xyz = (t_mtx **)v_alloc(sizeof(t_mtx) * 3);
	out->xyz[0] = mtx_new("X", 4, 4);
	out->xyz[1] = mtx_new("Y", 4, 4);
	out->xyz[2] = mtx_new("Z", 4, 4);
	out->pos = mtx_new("p", 1, 3);
	out->ori = mtx_new("o", 1, 3);
	out->rot = mtx_new("R", 4, 4);
	out->scl = mtx_new("S", 4, 4);
	out->tt = mtx_new("tT", 4, 4);
	out->comp = mtx_new("CO", 4, 4);
	if (verbose > 0)
		printf("\nObject constructed!\n\n");
	return (out);
}
