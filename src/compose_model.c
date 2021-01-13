/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:49:24 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/11 10:38:07 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fdf.h"

static void		print_method(t_object obj)
{
	printf("\nComposing model: %s\n\n", obj.name);
	g_print_mtx(obj.rotx);
	g_print_mtx(obj.roty);
	g_print_mtx(obj.rotz);
	g_print_mtx(obj.rotation);
	g_print_mtx(obj.translation);
	g_print_mtx(obj.transformation);
	printf("\n%s composed:\n\n", obj.name);
}

t_mtx4			compose_model(t_object obj, int verbose)
{
	t_mtx4		tmp1;
	t_mtx4		tmp2;

	obj.rotx = g_rotx(obj.direction.x);
	obj.roty = g_roty(obj.direction.y);
	obj.rotz = g_rotz(obj.direction.z);
	tmp1 = g_mult_mtx(obj.rotx, obj.roty);
	obj.rotation = g_mult_mtx(tmp1, obj.rotz);
	obj.translation = g_translate(obj.position);
	obj.transformation = g_scale(obj.scale);
	tmp1 = g_mult_mtx(obj.rotation, obj.transformation);
	tmp2 = g_mult_mtx(tmp1, obj.translation);
	if (verbose > 0)
		print_method(obj);
	return (tmp2);
}
