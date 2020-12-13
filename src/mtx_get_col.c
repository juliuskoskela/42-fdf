/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_get_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:49:08 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:06:49 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double			*mtx_get_col(t_mtx *mtx, size_t col)
{
	size_t		i;
	size_t		j;
	double		*out;

	i = col;
	j = 0;
	out = (double *)v_alloc(sizeof(double) * mtx->y);
	while (i < mtx->x * mtx->y)
	{
		out[j] = mtx->this[i];
		j++;
		i = i + mtx->x;
	}
	return (out);
}
