/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:00:44 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 01:00:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fdf.h"

t_camera		create_camera(char *name, int verbose)
{
	t_camera	out;

	out.name = name;
	out.ratio = RESX / RESY;
	out.near = 1;
	out.far = 1000;
	out.fov = 60;
	out.position = g_vct4(0, 100, 0, 1);
	out.direction = g_vct4(45, 0, 0, 1);
	out.view_mtx = compose_view(out, verbose);
	out.proj_mtx = g_proj(out.fov, out.ratio, out.near, out.far);
	if (verbose > 0)
		printf("Camera created!\n\n");
	return (out);
}
