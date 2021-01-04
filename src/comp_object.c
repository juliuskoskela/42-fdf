/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:49:24 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/04 05:30:01 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fdf.h"

void			comp_object(t_object **obj, int verbose)
{
	t_mtx		**tmp;

	tmp = (t_mtx **)v_alloc(sizeof(t_mtx) * 3);
	g_rotx((*obj)->xyz[2], (*obj)->ori->this[0]);
	g_roty((*obj)->xyz[1], (*obj)->ori->this[1]);
	g_rotz((*obj)->xyz[0], (*obj)->ori->this[2]);
	mtx_arr_multiply((*obj)->rot, (*obj)->xyz, 3);
	g_trans((*obj)->tt, (*obj)->pos);
	g_scale((*obj)->scl, (*obj)->g_scale);
	tmp[0] = (*obj)->rot;
	tmp[1] = (*obj)->tt;
	tmp[2] = (*obj)->scl;
	mtx_arr_multiply((*obj)->comp, tmp, 3);
	if (verbose == 1)
		printf("\nObject matrix composited!\n\n");
}
