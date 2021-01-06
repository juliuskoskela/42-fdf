/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vtx_tri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 02:33:15 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 05:06:37 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_dlist			*map_vtx_tri(t_dlist *buff, size_t x)
{
	t_dlist		*pos1;
	t_dlist		*pos2;
	t_dlist		*out;
	t_tri		*tri;
	size_t		i;

	pos1 = buff;
	pos2 = buff;
	i = 0;
	out = NULL;
	while (i < x + 1)
	{
		pos2 = pos2->next;
		i++;
	}
	i = 0;
	while (pos2)
	{
		i++;
		if (i != x)
		{
			tri = tri_new(pos1->content, pos1->next->content, pos2->prev->content);
			dl_putlast(&out, tri);
			tri = tri_new(pos2->content, pos2->prev->content, pos1->next->content);
			dl_putlast(&out, tri);
		}
		else
			i = 0;
		pos1 = pos1->next;
		pos2 = pos2->next;
	}
	return (out);
}
