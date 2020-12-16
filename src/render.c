/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 06:58:30 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/15 18:30:19 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			render(t_program *fdf)
{
	t_dlist		*tmp;
	double		*org;

	tmp = fdf->world->world_buffer[0]->object_buffer;
	while (tmp)
	{
		org = tmp->content;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)org[0], (int)org[1], 0xFFFFFF - (org[4]));
		tmp = tmp->next;
	}
}
