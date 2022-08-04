/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:01:11 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 03:42:11 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world create_world(t_camera cam)
{
	t_world		wld;

	wld.mlx = mlx_init();
	wld.win = mlx_new_window(wld.mlx, RESX, RESY, "window");
	wld.buffer = allocate_buffer(MAX_BUFFER);
	wld.models = (t_model *)v_alloc(sizeof(t_model) * MAX_MODELS);
	wld.a_cam = cam;
	wld.obj_cnt = 0;
	if (g_verbose > 0)
		printf("SUCCESS: World created!\n");
	return (wld);
}
