/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:01:11 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 23:50:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world			create_world(char *name, int verbose)
{
	t_world		out;

	out.name = name;
	out.mlx_ptr = mlx_init();
	out.win_ptr = mlx_new_window(out.mlx_ptr, RESX, RESY, out.name);
	out.buffer = allocate_buffer(MAX_BUFF);
	out.objects = (t_object *)v_alloc(sizeof(t_object) * 10);
	out.camera_1 = create_camera(verbose);
	out.camera_2 = create_camera(verbose);
	out.camera_3 = create_camera(verbose);
	out.active_camera = out.camera_1;
	out.active_camera.index = 0;
	out.world_mtx = g_mult_mtx(out.active_camera.view_mtx, \
	out.active_camera.proj_mtx);
	out.obj_cnt = 0;
	out.tri_cnt = 0;
	if (verbose > 0)
		printf("World created!\n\n");
	return (out);
}
