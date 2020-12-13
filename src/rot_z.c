/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:54:49 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:09:44 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx			*rot_z(double angle)
{
	t_mtx		*out;
	double		rot_z[16] = { cos(angle), -sin(angle), 0.0, 0.0,
							sin(angle), cos(angle), 0.0, 0.0,
							0.0, 0.0, 1.0, 0.0,
							0.0, 0.0, 0.0, 1.0, };
	out = mtx_cpy(rot_z, 4, 4);
	out->name = s_dup("Z");
	return(out);
}
