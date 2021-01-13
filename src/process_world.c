/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:03:05 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 18:15:32 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world			process_world(t_world out, int verbose)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < out.obj_cnt)
	{
		while (j < out.objects[i].tri_cnt)
		{
			out.buffer[k] = g_mult_tri(out.world_mtx, out.objects[i].buffer[j]);
			j++;
			k++;
		}
		j = 0;
		i++;
	}
	out.tri_cnt = k;
	if (verbose > 0)
		printf("World processed!\n\n");
	return (out);
}
