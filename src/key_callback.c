/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:30:47 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 03:41:07 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void modify_world(t_world *w, int keycode)
{
	if (keycode == KEY_LEFT)
		w->a_cam.rot.x--;
	else if (keycode == KEY_RIGHT)
		w->a_cam.rot.x++;
	else if (keycode == KEY_DOWN)
		w->a_cam.rot.y--;
	else if (keycode == KEY_UP)
		w->a_cam.rot.y++;
	else if (keycode == KEY_F)
		w->a_cam.pos.z++;
	else if (keycode == KEY_G)
		w->a_cam.pos.z--;
	else if (keycode == KEY_D)
		w->a_cam.pos.x--;
	else if (keycode == KEY_A)
		w->a_cam.pos.x++;
	else if (keycode == KEY_W)
		w->a_cam.pos.y++;
	else if (keycode == KEY_S)
		w->a_cam.pos.y--;
}

int key_callback(int keycode, t_world *w)
{
	if (!w->mlx || !w->win || keycode < 0)
		error("Error in key callback params!\n");
	modify_world(w, keycode);
	if (keycode == KEY_1)
		w->projection = PERSPECTIVE;
	else if (keycode == KEY_2)
		w->projection = ORTHOGRAPHIC;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(w->mlx, w->win);
		exit(1);
	}
	mlx_clear_window(w->mlx, w->win);
	return (0);
}
