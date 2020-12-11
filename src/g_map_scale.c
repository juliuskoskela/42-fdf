/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_map_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:38:48 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/10 11:53:48 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			g_map_scale(t_vtxarr **map, double scalar)
{
	while (*map)
	{
		g_vtx_scale((*map)->vtx, scalar);
		*map = (*map)->next;
	}
}
