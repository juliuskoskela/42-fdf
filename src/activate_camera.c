/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:01:43 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 01:01:44 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fdf.h"

t_world			activate_camera(t_world out, size_t i, int verbose)
{
	out.active_camera = out.cameras[i];
	out.world_mtx = g_mult_mtx(out.active_camera.view_mtx, out.active_camera.proj_mtx);
	if (verbose > 0)
	{
		printf("Camera activated!\n\n");
		g_print_mtx(out.world_mtx);
	}
	return (out);
}
