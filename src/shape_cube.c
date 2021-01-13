/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 03:27:30 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/12 21:32:35 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_object		shape_cube(t_object obj)
{
	obj.shape = (t_vct4 *)v_alloc(sizeof(t_vct4) * 8);
	obj.shape[0] = g_vct4(0, 0, 0, 1);
	obj.shape[1] = g_vct4(0, 1, 0, 1);
	obj.shape[2] = g_vct4(1, 0, 0, 1);
	obj.shape[3] = g_vct4(1, 1, 0, 1);
	obj.shape[4] = g_vct4(0, 0, 1, 1);
	obj.shape[5] = g_vct4(0, 1, 1, 1);
	obj.shape[6] = g_vct4(1, 0, 1, 1);
	obj.shape[7] = g_vct4(1, 1, 1, 1);
	obj.vtx_cnt = 8;
	return (obj);
}
