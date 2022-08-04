/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:47:50 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 03:43:11 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

size_t process_buffer(t_buffer *v, t_mtx4 m)
{
	size_t	i;

	i = 0;
	while (i < v->size)
	{
		v->tri[i].a = g_mult_vct(m, v->tri[i].a);
		v->tri[i].b = g_mult_vct(m, v->tri[i].b);
		v->tri[i].c = g_mult_vct(m, v->tri[i].c);
		i++;
	}
	if (g_verbose > 0)
		printf("SUCCESS: %zu vertices processed!\n", i);
	return (i);
}
