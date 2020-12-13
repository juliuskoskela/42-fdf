/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:54:11 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:09:16 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx			*rot_x(double angle)
{
	t_mtx		*out;
	double		rot_x[16] = { 1.0, 0.0, 0.0, 0.0,
							0.0, cos(angle), -sin(angle), 0.0,
							0.0, sin(angle), cos(angle), 0.0,
							0.0, 0.0, 0.0, 1.0, };
	out = mtx_cpy(rot_x, 4, 4);
	out->name = s_dup("X");
	return(out);
}
