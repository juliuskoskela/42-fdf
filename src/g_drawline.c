/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_drawline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 08:31:21 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/08 09:32:54 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			g_drawline(t_program *p, t_vertex org, t_vertex dst)
{
	t_vertex	tmp;

	tmp = org;
	while (tmp.x <= dst.x && tmp.y <= dst.y)
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, (int)tmp.x, (int)tmp.y, 0xFFFFFF);
		tmp.x = tmp.x + 1.0;
		tmp.y = tmp.y + 1.0;
	}
}
