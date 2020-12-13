/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_get_row.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:48:42 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:07:24 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double			*mtx_get_row(t_mtx *mtx, size_t row)
{
	size_t		i;
	size_t		j;
	double		*out;

	i = row * mtx->x;
	j = 0;
	out = (double *)v_alloc(sizeof(double) * mtx->x);
	while (i < (row + 1) * mtx->x)
	{
		out[j] = mtx->this[i];
		j++;
		i++;
	}
	return (out);
}
