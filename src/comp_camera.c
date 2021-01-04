/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:49:01 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/04 05:30:14 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			comp_camera(t_camera **cam, int verbose)
{
	view_mtx(*cam, verbose);
	g_proj((*cam)->proj_mtx, (*cam)->fov, (*cam)->ratio, (*cam)->near, (*cam)->far);
	mtx_multiply((*cam)->comp, (*cam)->view_mtx, (*cam)->proj_mtx);
	if (verbose == 1)
		printf("\nCamera matrix composited!\n\n");
}
