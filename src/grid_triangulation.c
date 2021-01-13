/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_triangulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:55:21 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/12 22:16:11 by jkoskela         ###   ########.fr       */
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
			d[k].a = s[i];
			d[k].b = s[i + 1];
			d[k].c = s[i + w];
			d[k + 1].a = s[i + w + 1];
			d[k + 1].b = s[i + 1];
			d[k + 1].c = s[i + w];
			k += 2;
			i++;
			j++;
		}
	}
	return (d);
}
