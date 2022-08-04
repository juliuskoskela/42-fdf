/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:00:44 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 03:57:11 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_camera create_camera(t_vct4 vrs, size_t id)
{
	t_camera	cam;

	cam.id = id;
	cam.fov = vrs.x;
	cam.ratio = vrs.y;
	cam.near = vrs.z;
	cam.far = vrs.w;
	cam.pos = (t_vct4) {0.0, 0.0, 0.0, 1.0};
	cam.rot = (t_vct4) {0.0, 0.0, 0.0, 1.0};
	if (g_verbose > 0)
		printf("SUCCESS: Camera created!\n");
	return (cam);
}
