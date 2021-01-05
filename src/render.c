/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:57:45 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/05 06:00:11 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			render(t_world **wrld)
{
	t_dlist		*tmp;
	t_mtx		*cast;

	tmp = (*wrld)->wrld_buff;
	while (tmp)
	{
		cast = tmp->content;
		mlx_pixel_put((*wrld)->mlx_ptr, (*wrld)->win_ptr, cast->this[0], cast->this[1], 0xFFFFFF);
		tmp = tmp->next;
	}
}
