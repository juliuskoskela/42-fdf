/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 02:36:08 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/10 22:15:57 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			print_tri(t_dlist *tris)
{
	t_dlist		*tmp;
	t_tri		*cast;
	size_t		i;

	tmp = tris;
	i = 0;
	while (tmp)
	{
		cast = tmp->content;
		printf("%zu\nv1 (%.1f, %.1f, %.1f) (%.1f)\n", i, cast->ax, \
		cast->ay, cast->az, cast->aw);
		printf("%zu\nv1 (%.1f, %.1f, %.1f) (%.1f)\n", i, cast->bx, \
		cast->by, cast->bz, cast->bw);
		printf("%zu\nv1 (%.1f, %.1f, %.1f) (%.1f)\n", i, cast->cx, \
		cast->cy, cast->cz, cast->cw);
		tmp = tmp->next;
		i++;
	}
}
