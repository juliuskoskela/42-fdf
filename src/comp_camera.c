/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:49:01 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 04:44:59 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			comp_camera(t_camera **cam, int verbose)
{
	view_mtx(*cam, 0);
	g_proj((*cam)->g_proj, (*cam)->fov, (*cam)->ratio, (*cam)->near, (*cam)->far);
	mtx_multiply((*cam)->comp, (*cam)->view_mtx, (*cam)->g_proj);
	if (verbose > 0)
		printf("\nCamera matrix composited!\n\n");
}
