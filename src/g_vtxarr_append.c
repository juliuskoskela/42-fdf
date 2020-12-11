/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vtxarr_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 08:50:00 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/08 08:52:04 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		g_vtxarr_append(t_vtxarr **ref, t_vertex *new)
{
	t_vtxarr	*temp;
	t_vtxarr	*ptr;

	ptr = NULL;
	temp = (t_vtxarr *)malloc(sizeof(t_vtxarr));
	temp->vtx = new;
	temp->prev = NULL;
	temp->next = NULL;
	if (*ref == NULL)
		(*ref) = temp;
	else
	{
		ptr = (*ref);
		while (ptr->next != NULL)
			ptr = ptr->next;
		temp->prev = ptr;
		ptr->next = temp;
	}
}