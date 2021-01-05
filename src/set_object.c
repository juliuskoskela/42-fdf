/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:51:41 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/05 07:30:08 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			set_object(t_object **obj, int verbose)
{

	(*obj)->pos->this[0] = RESX / 2;
	(*obj)->pos->this[1] = RESY / 3;
	(*obj)->pos->this[2] = 100.0;
	(*obj)->ori->this[0] = 0;
	(*obj)->ori->this[1] = 0;
	(*obj)->ori->this[2] = 0;
	(*obj)->g_scale = 20;
	(*obj)->obj_buff = input_parse((*obj)->file);
	(*obj)->vtx_cnt = dl_len((*obj)->obj_buff);
	if (verbose == 1)
		printf("\nObject set!\n\n");
}
