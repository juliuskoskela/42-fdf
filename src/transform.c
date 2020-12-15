/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 02:49:49 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/15 02:49:50 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			transform(t_dlist *verteces, t_mtx *object_mtx)
{
	t_dlist		*pos;
	double		*tmp;

	pos = verteces;
	while (pos)
	{
		tmp = pos->content;
		pos->content = (void *)mtx_vtx(object_mtx, tmp);
		pos = pos->next;
	}
}
