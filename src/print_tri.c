/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 02:36:08 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 02:36:15 by jkoskela         ###   ########.fr       */
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
		printf("%zu\nv1 (%.1f, %.1f, %.1f) (%.1f)\n", i, cast->v1->this[0], \
		cast->v1->this[1], cast->v1->this[2], cast->v1->this[3]);
		printf("v2 (%.1f, %.1f, %.1f) (%.1f)\n", cast->v2->this[0], \
		cast->v2->this[1], cast->v2->this[2], cast->v2->this[3]);
		printf("v3 (%.1f, %.1f, %.1f) (%.1f)\n\n", cast->v3->this[0], \
		cast->v3->this[1], cast->v3->this[2], cast->v3->this[3]);
		tmp = tmp->next;
		i++;
	}
}
