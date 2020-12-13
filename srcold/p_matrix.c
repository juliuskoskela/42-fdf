/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_matrix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:21:09 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:04:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void			p_matrix(t_matrix *mtx, char *name)
{
	printf("%s |  mx  |  my  |  mz  |  mw  |\n", name);
	printf("--|------|------|------|------|\n");
	printf("x | %4.1f | %4.1f | %4.1f | %4.1f |\n", \
	mtx->mx->x, mtx->my->x, mtx->mz->x, mtx->mw->x);
	printf("y | %4.1f | %4.1f | %4.1f | %4.1f |\n", \
	mtx->mx->y, mtx->my->y, mtx->mz->y, mtx->mw->y);
	printf("z | %4.1f | %4.1f | %4.1f | %4.1f |\n", \
	mtx->mx->z, mtx->my->z, mtx->mz->z, mtx->mw->z);
	printf("w | %4.1f | %4.1f | %4.1f | %4.1f |\n\n", \
	mtx->mx->w, mtx->my->w, mtx->mz->w, mtx->mw->w);
}
