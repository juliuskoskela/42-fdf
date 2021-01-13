/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 03:27:30 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/12 21:32:30 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_object			shape_tetra(t_object obj)
{
	obj.shape = (t_vct4 *)v_alloc(sizeof(t_vct4) * 4);
	obj.shape[0] = g_vct4(sqrt(8 / 9), 0, -(1 / 3), 1);
	obj.shape[1] = g_vct4(-sqrt(2 / 9), sqrt(2 / 3), -(1 / 3), 1);
	obj.shape[2] = g_vct4(-sqrt(2 / 9), -sqrt(2 / 3), -(1 / 3), 1);
	obj.shape[3] = g_vct4(0, 0, 1, 1);
	obj.vtx_cnt = 4;
	return (obj);
}
