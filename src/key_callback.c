/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:30:47 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 23:55:53 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world			move_camera(t_world wrld, int x, int y, int z)
{
	wrld.active_camera.position.x += x;
	wrld.active_camera.position.y += y;
	wrld.active_camera.position.z += z;
	wrld.active_camera.view_mtx = compose_view(wrld.active_camera, 0);
	wrld.world_mtx = g_mult_mtx(wrld.active_camera.view_mtx, \
	wrld.active_camera.proj_mtx);
	wrld = process_world(wrld, 0);
	return (wrld);
}

t_world			rotate_camera(t_world wrld, int x, int y, int z)
{
	wrld.active_camera.direction.x += x;
	wrld.active_camera.direction.y += y;
	wrld.active_camera.direction.z += z;
	wrld.active_camera.view_mtx = compose_view(wrld.active_camera, 0);
	wrld.world_mtx = g_mult_mtx(wrld.active_camera.view_mtx, \
	wrld.active_camera.proj_mtx);
	wrld = process_world(wrld, 0);
	return (wrld);
}

t_world			change_camera(t_world wrld)
{
	if (wrld.active_camera.index == 0)
	{
		wrld.camera_1 = wrld.active_camera;
		wrld.active_camera = wrld.camera_2;
	}
	else if (wrld.active_camera.index == 1)
	{
		wrld.camera_2 = wrld.active_camera;
		wrld.active_camera = wrld.camera_3;
	}
	else if (wrld.active_camera.index == 2)
	{
		wrld.camera_3 = wrld.active_camera;
		wrld.active_camera = wrld.camera_1;
	}
	wrld.active_camera.view_mtx = compose_view(wrld.active_camera, 0);
	wrld.world_mtx = g_mult_mtx(wrld.active_camera.view_mtx, \
	wrld.active_camera.proj_mtx);
	wrld = process_world(wrld, 0);
	return (wrld);
}

int				key_callback(int keycode, t_world *wrld)
{
	if (!wrld->mlx_ptr || !wrld->win_ptr || keycode < 0)
		error("Error in key callback params\n");
	// Rotate Left
	if (keycode == 123)
		*wrld = rotate_camera(*wrld, -1, 0, 0);
	// Rotate Right
	else if (keycode == 124)
		*wrld = rotate_camera(*wrld, 1, 0, 0);
	// Rotate Down
	else if (keycode == 125)
		*wrld = rotate_camera(*wrld, 0, -1, 0);
	// Rotate Up
	else if (keycode == 126)
		*wrld = rotate_camera(*wrld, 0, 1, 0);
	// Move forward
	else if (keycode == 12)
		*wrld = move_camera(*wrld, 0, 0, 1);
	// Move backward
	else if (keycode == 14)
		*wrld = move_camera(*wrld, 0, 0, -1);
	// Move up
	else if (keycode == 13)
		*wrld = move_camera(*wrld, 0, 1, 0);
	// Move down
	else if (keycode == 1)
		*wrld = move_camera(*wrld, 0, -1, 0);
	// Move left
	else if (keycode == 0)
		*wrld = move_camera(*wrld, -1, 0, 0);
	// Move right
	else if (keycode == 2)
		*wrld = move_camera(*wrld, 1, 0, 0);
	// Change camera
	else if (keycode == 8)
	{
		*wrld = change_camera(*wrld);
	}
	// Exit
	else if (keycode == 53)
	{
		mlx_destroy_window(wrld->mlx_ptr, wrld->win_ptr);
		exit(1);
	}
	mlx_clear_window(wrld->mlx_ptr, wrld->win_ptr);
	render(*wrld);
	return (0);
}
