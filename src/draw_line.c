/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:10:51 by jkoskela          #+#    #+#             */
/*   Updated: 2021/03/02 19:03:13 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int		*assign_variables(t_vct4 v0, t_vct4 v1)
{
	int			*vars;

	vars = (int *)v_alloc(sizeof(int) * 10);
	vars[0] = v0.x;
	vars[1] = v1.x;
	vars[2] = v0.y;
	vars[3] = v1.y;
	vars[4] = abs(vars[1] - vars[0]);
	vars[5] = vars[0] < vars[1] ? 1 : -1;
	vars[6] = -abs(vars[3] - vars[2]);
	vars[7] = vars[2] < vars[3] ? 1 : -1;
	vars[8] = vars[4] + vars[6];
	return (vars);
}

void			draw_line(void *mlx, void *win, t_vct4 v0, t_vct4 v1)
{
	int			*vars;

	vars = assign_variables(v0, v1);
	while (1)
	{
		mlx_pixel_put(mlx, win, vars[0], vars[2], 0xFFFFFF);
		if (vars[0] == vars[1] && vars[2] == vars[3])
			break ;
		vars[9] = 2 * vars[8];
		if (vars[9] >= vars[6])
		{
			vars[8] += vars[6];
			vars[0] += vars[5];
		}
		if (vars[9] <= vars[4])
		{
			vars[8] += vars[4];
			vars[2] += vars[7];
		}
	}
	free(vars);
}
