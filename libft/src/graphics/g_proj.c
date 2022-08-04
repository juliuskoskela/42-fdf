/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_proj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:35:18 by jkoskela          #+#    #+#             */
/*   Updated: 2021/03/06 10:00:16 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_mtx4			g_proj(double fv, double rt, double n, double f)
{
	t_mtx4		projection;
	double		tan_half_fov;
	double		r;

	tan_half_fov = tan(0.5 * m_rad(fv));
	r = f - n;
	projection.v1 = (t_vct4) {1.0 / (tan_half_fov * rt), 0.0, 0.0, 0.0};
	projection.v2 = (t_vct4) {0.0, 1.0 / tan_half_fov, 0.0, 0.0};
	projection.v3 = (t_vct4) {0.0, 0.0, (f + n) / r, f * n / r};
	projection.v4 = (t_vct4) {0.0, 0.0, -1.0, 0.0};
	return (projection);
}

/*
**  ----------------------------------------------------------------------------
**
**	g_proj
**
**	3D to 2D projection matrix.
**	`fv` = field of view in degrees
**	`rt` = ratio (for example 16 / 9)
**	`n` = nearest pixel to the camera to be rendered
**	`f` = furthest pixel to the camera to be rendered
**
**  ----------------------------------------------------------------------------
*/
