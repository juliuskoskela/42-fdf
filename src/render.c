/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:57:45 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/04 03:40:58 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			render(t_world **wrld, t_mtx **buff, size_t buffsize)
{
	size_t		i;
	int			x;
	int			y;

	i = 0;
	while (i < buffsize)
	{
		x = (int)buff[i]->this[0];
		y = (int)buff[i]->this[1];
		mlx_pixel_put((*wrld)->mlx_ptr, (*wrld)->win_ptr, x, y, 0xFFFFFF);
		i++;
	}
}
