/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:53:20 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 19:49:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx			*projection(double ratio, double near, double far, double fov)
{
	t_mtx		*out;
	double		proj[16] = { 1.0, 0.0, 0.0, 0.0,
							0.0, 1.0, 0.0, 0.0,
							0.0, 0.0, 1.0, 0.0,
							0.0, 0.0, 0.0, 1.0, };
	proj[5] = 1 / tan(0.5 * m_rad(fov));
	proj[0] = proj[5] / ratio;
	proj[10] = -1 * (-near - far) / (near - far);
	proj[11] = (2 * near * far) / (near- far);
	proj[14] = -1;
	proj[15] = 0.0;
	out = mtx_cpy(proj, 4, 4);
	out->name = s_dup("P");
	return(out);
}
