/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:25:11 by esukava           #+#    #+#             */
/*   Updated: 2020/12/15 18:34:23 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			key_callback(int keycode, t_program *p)
{
	if (!p || !p->mlx_ptr || !p->win_ptr || keycode < 0)
		error("Error in key callback params");
	// Left
	if (keycode == 123)
	{
		p->world->camera->rot[0] += -1;
		p->world->transform(p->world->world_buffer[0]->object_buffer, \
		p->world->camera->view_mtx(p->world->camera->pos, \
		p->world->camera->rot));
	}
	// Right
	else if (keycode == 124)
	{
		p->world->camera->rot[0] += 1;
		p->world->transform(p->world->world_buffer[0]->object_buffer, \
		p->world->camera->view_mtx(p->world->camera->pos, \
		p->world->camera->rot));
	}
	// Down
	else if (keycode == 125)
	{
		p->world->camera->rot[1] += -1;
		p->world->transform(p->world->world_buffer[0]->object_buffer, \
		p->world->camera->view_mtx(p->world->camera->pos, \
		p->world->camera->rot));
	}
	// Up
	else if (keycode == 126)
	{
		p->world->camera->rot[1] += 1;
		p->world->transform(p->world->world_buffer[0]->object_buffer, \
		p->world->camera->view_mtx(p->world->camera->pos, \
		p->world->camera->rot));
	}
	// Exit
	else if (keycode == 53)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit(1);
	}
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	render(p);
	return (0);
}
