/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_multiply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:51:02 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 21:30:53 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx			*mtx_multiply(t_mtx *a, t_mtx *b)
{
	size_t		i;
	size_t		j;
	size_t		k;
	t_mtx		*out;

	i = 0;
	j = 0;
	k = 0;
	out = mtx_new("M", a->x, b->y);
	while (i < a->x * a->y)
	{
		if (k == a->x)
		{
			k = 0;
			j++;
		}
		out->this[i] = m_dot(mtx_get_row(a, j), mtx_get_col(b, k), a->x);
		i++;
		k++;
	}
	return (out);
}
