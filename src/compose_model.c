/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_model.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:22:36 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 22:54:52 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
		printf("Model matrix composed!\n\n");
	return (tmp2);
}
