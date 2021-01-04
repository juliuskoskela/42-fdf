/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:52:38 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/04 05:50:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			set_world(t_world **wrld, int verbose)
{
	(*wrld)->name = s_dup("fdf");
	(*wrld)->resx = RESX;
	(*wrld)->resy = RESY;
	(*wrld)->mlx_ptr = mlx_init();
	(*wrld)->win_ptr = mlx_new_window((*wrld)->mlx_ptr, RESX, RESY, "fdf");
	if (verbose == 1)
		printf("\nWorld set!\n\n");
}
