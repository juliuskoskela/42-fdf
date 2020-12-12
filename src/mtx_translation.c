/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_translation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:18:29 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/12 07:58:06 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_matrix		*mtx_translation(t_vertex *vtx)
{
	t_matrix	*out;

	out = mtx_id(1);
	out->mw->x = vtx->x;
	out->mw->y = vtx->y;
	out->mw->z = vtx->z;
	return (out);
}
