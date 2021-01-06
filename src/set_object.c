/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:51:41 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 05:13:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			set_object(t_object **obj, int verbose)
{

	(*obj)->pos->this[0] = RESX / 2;
	(*obj)->pos->this[1] = RESY / 3;
	(*obj)->pos->this[2] = 0;
	(*obj)->ori->this[0] = 60;
	(*obj)->ori->this[1] = 0;
	(*obj)->ori->this[2] = 0;
	(*obj)->g_scale = 10;
	(*obj)->obj_vtx_buff = input_parse((*obj)->file);
	(*obj)->obj_tri_buff = map_vtx_tri((*obj)->obj_vtx_buff, 19);
	(*obj)->vtx_cnt = dl_len((*obj)->obj_vtx_buff);
	if (verbose > 0)
		printf("\nObject set!\n\n");
}
