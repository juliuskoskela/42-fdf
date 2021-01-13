/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 03:21:13 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 22:55:21 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx4			compose_view(t_camera cam, int verbose)
{
	t_mtx4		tmp;

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
		printf("View matrix composed!\n\n");
	return (tmp);
}
