/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_triangulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:55:21 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 18:17:11 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_tri			*grid_triangulation(t_tri *d, t_vct4 *s, size_t w, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	k = 0;
	j = 0;
	while (i < size - w)
	{
		if (j == w - 1)
		{
			j = 0;
			i++;
		}
		else
		{
			d[k] = g_tri(s[i], s[i + 1], s[i + w]);
			d[k + 1] = g_tri(s[i + w + 1], s[i + 1], s[i + w]);
			k += 2;
			i++;
			j++;
		}
	}
	return (d);
}
