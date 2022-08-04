/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_from_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:56:12 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 03:43:18 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

size_t view_from_world(t_world *wld)
{
	t_mtx4	m;
	size_t	i;

	m = g_view(wld->a_cam.rot, wld->a_cam.pos);
	i = process_buffer(&wld->buffer, m);
	if (g_verbose > 0)
		printf("SUCCESS: %zu world vertices converted to view space!\n", i);
	return (i);
}
