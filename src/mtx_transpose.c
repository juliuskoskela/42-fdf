/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_transpose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:31:23 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/14 17:34:46 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx			*mtx_transpose(t_mtx *in)
{
	t_mtx		*out;
	double		*row;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	out = mtx_new("Tr", in->y, in->x);
	while (i < out->y)
	{
		row = mtx_get_col(in, i);
		while (j < out->x)
		{
			out->this[k] = row[j];
			j++;
			k++;
		}
		j = 0;
		i++;
	}
	return (out);
}
