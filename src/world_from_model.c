/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_from_model.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:55:14 by jkoskela          #+#    #+#             */
/*   Updated: 2021/03/08 16:18:19 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

size_t			copy_model_buffer(t_buffer *d, t_buffer *s, t_mtx4 m, size_t k)
{
	size_t		i;

	i = 0;
	while (i < s->size)
	{
		if (k >= MAX_BUFFER)
		{
			printf("ERROR: World buffer capacity exceeded at %zu!\n", k);
			return (0);
		}
		d->tri[k].a = g_mult_vct(m, s->tri[i].a);
		d->tri[k].b = g_mult_vct(m, s->tri[i].b);
		d->tri[k].c = g_mult_vct(m, s->tri[i].c);
		i++;
		k++;
	}
	return (k);
}

size_t			world_from_model(t_world *wld)
{
	t_mtx4		m;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < wld->obj_cnt)
	{
		m = g_model(wld->models[i].rot, \
		wld->models[i].pos, wld->models[i].scale);
		j = copy_model_buffer(&wld->buffer, &wld->models[i].buffer, m, j);
		i++;
	}
	wld->buffer.size = j;
	if (g_verbose > 0)
		printf("SUCCESS: %zu model vertices converted to world space!\n", j);
	return (j);
}
