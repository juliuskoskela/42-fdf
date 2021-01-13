/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:30:47 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 02:09:08 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world			move_camera(t_world wrld, int x, int y, int z)
{
	wrld.active_camera.position.x += x;
	wrld.active_camera.position.y += y;
	wrld.active_camera.position.z += z;
	wrld.active_camera.view_mtx = compose_view(wrld.active_camera, 0);
	wrld.world_mtx = g_mult_mtx(wrld.active_camera.view_mtx, wrld.active_camera.proj_mtx);
	wrld = process_world(wrld, 0);
	return (wrld);
}

t_world			rotate_camera(t_world wrld, int x, int y, int z)
{
	wrld.active_camera.direction.x += x;
	wrld.active_camera.direction.y += y;
	wrld.active_camera.direction.z += z;
	wrld.active_camera.view_mtx = compose_view(wrld.active_camera, 0);
	wrld.world_mtx = g_mult_mtx(wrld.active_camera.view_mtx, wrld.active_camera.proj_mtx);
	wrld = process_world(wrld, 0);
	return (wrld);
}

int				key_callback(int keycode, t_world *wrld)
{
	if (!wrld->mlx_ptr || !wrld->win_ptr || keycode < 0)
		error("Error in key callback params\n");
	// Left
	if (keycode == 123)
	{
		*wrld = rotate_camera(*wrld, -1, 0, 0);
	}
	// Right
	else if (keycode == 124)
	{
		*wrld = rotate_camera(*wrld, 1, 0, 0);
	}
	// Down
	else if (keycode == 125)
	{
		*wrld = rotate_camera(*wrld, 0, -1, 0);
	}
	// Up
	else if (keycode == 126)
	{
		*wrld = rotate_camera(*wrld, 0, 1, 0);
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
