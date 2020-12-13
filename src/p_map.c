/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:36:05 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:44:55 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			p_map(t_dlist **map)
{
	double		*tmp;
	if (*map)
	{
		tmp = (*map)->content;
		printf("v.x: %f v.y: %f v.z: %f v.w: %f\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		*map = (*map)->next;
		p_map(map);
	}
}
