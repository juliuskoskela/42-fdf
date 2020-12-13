/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:54:28 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:09:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx			*rot_y(double angle)
{
	t_mtx		*out;
	double		rot_y[16] = { cos(angle), 0.0, sin(angle), 0.0,
							0.0, 1.0, 0.0, 0.0,
							-sin(angle), 0.0, cos(angle), 0.0,
							0.0, 0.0, 0.0, 1.0, };
	out = mtx_cpy(rot_y, 4, 4);
	out->name = s_dup("Y");
	return(out);
}
