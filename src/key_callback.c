/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:25:11 by esukava           #+#    #+#             */
/*   Updated: 2020/12/15 06:30:18 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		call_sec(t_program *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	draw_sec(p);
}

void		call_isom(t_program *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	draw_isom(p);
}

int			key_callback(int keycode, t_program *p)
{
	if (keycode == 1 || keycode == 7)
		scale(keycode, p);
	if (keycode == 0 || keycode == 6)
		zoom(keycode, p);
	// Left
	if (keycode == 123)
	{}
	// Right
	if (keycode == 124)
	{}
	// Down
	if (keycode == 125)
	{}
	// Up
	if (keycode == 126)
	{}
	// Exit
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit(1);
	}
	return (0);
}
