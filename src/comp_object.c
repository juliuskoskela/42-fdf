/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:49:24 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 23:13:06 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fdf.h"

static void		print_method(t_object *obj, int verbose)
{
	if (verbose == 2)
	{
		mtx_print(obj->xyz[0]);
		mtx_print(obj->xyz[1]);
		mtx_print(obj->xyz[2]);
		mtx_print(obj->rot);
		mtx_print(obj->tt);
		mtx_print(obj->scl);
		mtx_print(obj->comp);
	}
	printf("\nObject matrix composited!\n\n");
}

void			comp_object(t_object *obj, int verbose)
{
	g_rotx(obj->xyz[0], obj->ori->this[0]);
	g_roty(obj->xyz[1], obj->ori->this[1]);
	g_rotz(obj->xyz[2], obj->ori->this[2]);
	mtx_multiply(obj->rot, obj->xyz[0], obj->xyz[1]);
	mtx_multiply(obj->rot, obj->rot, obj->xyz[2]);
	g_trans(obj->tt, obj->pos);
	g_scale(obj->scl, obj->g_scale);
	mtx_multiply(obj->comp, obj->rot, obj->tt);
	mtx_multiply(obj->comp, obj->comp, obj->scl);
	if (verbose > 0)
		print_method(obj, verbose);
}
