/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:52:26 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/02 01:19:01 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		free_obj_buff(t_dlist *buff)
{
	t_mtx		*cast;
	t_dlist		*tmp;

	tmp = buff;
	while (tmp)
	{
		cast = tmp->content;
		mtx_free(cast);
		tmp = tmp->next;
	}
	dl_del_list(buff);
	buff = NULL;
}

void			destruct_object(t_object *obj, int verbose)
{
	mtx_free(obj->comp);
	mtx_free(obj->rot);
	mtx_free(obj->scl);
	mtx_free(obj->xyz[0]);
	mtx_free(obj->xyz[1]);
	mtx_free(obj->xyz[2]);
	mtx_free(obj->rot);
	mtx_free(obj->tt);
	free_obj_buff(obj->object_buff);
	free(obj->ori);
	free(obj->pos);
	free(obj->pos);
	if (verbose == 1)
		printf("\nObject destructed!\n\n");
}