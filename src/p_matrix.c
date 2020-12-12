/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_matrix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:21:09 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/12 04:30:26 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			p_matrix(t_matrix *mtx)
{
	printf("M | mx | my | mz | mw |\n-----------------------\nx | %0.1f | %0.1f | %0.1f | %0.1f |\ny | %0.1f | %0.1f | %0.1f | %0.1f |\nz | %0.1f | %0.1f | %0.1f | %0.1f |\nw | %0.1f | %0.1f | %0.1f | %0.1f |\n\n",
			mtx->mx->x, mtx->my->x, mtx->mz->x, mtx->mw->x,
			mtx->mx->y, mtx->my->y, mtx->mz->y, mtx->mw->y,
			mtx->mx->z, mtx->my->z, mtx->mz->z, mtx->mw->z,
			mtx->mx->w, mtx->my->w, mtx->mz->w, mtx->mw->w
			);
}
