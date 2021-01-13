/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 03:21:13 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 03:16:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		print_method(t_camera cam)
{
	printf("\nComposing view for: %s\n\n", cam.name);
	g_print_mtx(cam.rotx);
	g_print_mtx(cam.roty);
	g_print_mtx(cam.rotz);
	g_print_mtx(cam.rotation);
	g_print_mtx(cam.tr);
	g_print_mtx(cam.tt);
	g_print_vct(cam.ovct, 0);
	printf("\n%s composed:\n\n", cam.name);
}

t_mtx4			compose_view(t_camera cam, int verbose)
{
	t_mtx4		tmp;

	tmp.name = s_dup("V");
	cam.rotx = g_rotx(cam.direction.x);
	cam.roty = g_roty(cam.direction.y);
	cam.rotz = g_rotz(cam.direction.z);
	tmp = g_mult_mtx(cam.rotx, cam.roty);
	cam.rotation = g_mult_mtx(tmp, cam.rotz);
	cam.tr = g_transpose(cam.rotation);
	cam.ovct = g_opp(cam.position);
	cam.tt = g_translate(cam.ovct);
	tmp = g_mult_mtx(cam.tt, cam.tr);
	if (verbose > 0)
		print_method(cam);
	return (tmp);
}
