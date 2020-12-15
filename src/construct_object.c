/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 02:52:28 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/15 05:26:12 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_object		*construct_object(t_dlist *object_buffer)
{
	t_object	*out;

	out = (t_object *)v_alloc(sizeof(t_object));
	out->scalar = 1.0;
	out->pos = NULL;
	out->rot = NULL;
	out->object_buffer = object_buffer;
	out->rotate = &rotation;
	out->scale = &identity;
	out->move = &translation;
	out->object_cmp = &object_mtx;
	out->transform = &transform;
	return (out);
}
