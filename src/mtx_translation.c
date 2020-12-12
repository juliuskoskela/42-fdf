/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_translation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:18:29 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/12 04:18:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_matrix		*mtx_translation(t_vertex *vtx)
{
	t_matrix	*out;

	out = mtx_id(1);
	out->mx->w = vtx->x;
	out->my->w = vtx->y;
	out->mz->w = vtx->z;
	return (out);
}
