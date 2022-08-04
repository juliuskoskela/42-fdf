/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_triangulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:55:21 by jkoskela          #+#    #+#             */
/*   Updated: 2021/03/08 17:23:38 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
**	We have a square s[0], s[1], s[w], s[w + 1]. We interpret this square as
**	two triangles which are saved in the buffer `d`. We can "fold" the square
**	along axis v_1 = s[0] - s[w + 1] or v_2 = s[1] - s[w]. We calculate the
**	magnitude of v_1 and v_2 and choose the lower magnitude vector as our
**	folding diagonal.
*/

void			choose_diagonal(t_tri *d, t_vct4 *s, size_t w)
{
	if (g_mag(g_sub(s[0], s[w + 1]))
		< g_mag(g_sub(s[1], s[w])))
	{
		d[0] = (t_tri) {s[0], s[1], s[w], 0XFFFFFF};
		d[0 + 1] = (t_tri) {s[w + 1], s[1], s[w], 0XFFFFFF};
	}
	else
	{
		d[0] = (t_tri) {s[1], s[0], s[w + 1], 0XFFFFFF};
		d[0 + 1] = (t_tri) {s[w], s[0], s[w + 1], 0XFFFFFF};
	}
}

/*
**	We iterate through the verticies in buffer `s`. for each vertex (instead
**	of the last vertex of each line and the last row verticies) and copy
**	two triangles (one square) to the triangle buffer `d`. Choose diagonal
**	chooses the correct folding axis for each "square".
*/

t_tri			*grid_triangulation(t_tri *d, t_vct4 *s, size_t w, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size - w)
	{
		if (j == w - 1)
			j = 0;
		else
		{
			choose_diagonal(&d[k], &s[i], w);
			k += 2;
			j++;
		}
		i++;
	}
	return (d);
}

/*
**	Triangulates a planar mesh that is rectangular in the x/y axis and with
** 	a known width and height. Outputs an array of triangles. Destination array
**	`d` must be pre-allocated.
*/
