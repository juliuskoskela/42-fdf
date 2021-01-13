/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:03:05 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 01:03:09 by jkoskela         ###   ########.fr       */
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
			out.buffer[k].a = g_mult_vct(out.world_mtx, out.objects[i].buffer[j].a);
			out.buffer[k].b = g_mult_vct(out.world_mtx, out.objects[i].buffer[j].b);
			out.buffer[k].c = g_mult_vct(out.world_mtx, out.objects[i].buffer[j].c);
			j++;
			k++;
		}
		j = 0;
		i++;
	}
	out.tri_cnt = k;
	if (verbose > 0)
	{
		printf("World processed!\n\n");
		print_tri_arr(out.buffer, out.tri_cnt);
		g_print_mtx(out.world_mtx);
	}
	return (out);
}
