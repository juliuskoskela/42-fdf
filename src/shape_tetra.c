/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 03:27:30 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/11 05:49:22 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vct4			*shape_tetra()
{
	t_vct4		*out;

	out = (t_vct4 *)v_alloc(sizeof(t_vct4) * 4);
	out[0] = g_vct4(sqrt(8 / 9), 0, -(1 / 3), 1);
	out[1] = g_vct4(-sqrt(2 / 9), sqrt(2 / 3), -(1 / 3), 1);
	out[2] = g_vct4(-sqrt(2 / 9), -sqrt(2 / 3), -(1 / 3), 1);
	out[3] = g_vct4(0, 0, 1, 1);
	return (out);
}
