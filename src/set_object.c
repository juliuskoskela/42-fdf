/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:51:41 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/04 05:21:49 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			set_object(t_object **obj, int verbose)
{

	(*obj)->pos->this[0] = 0.0;
	(*obj)->pos->this[1] = 0.0;
	(*obj)->pos->this[2] = 0.0;
	(*obj)->ori->this[0] = 20;
	(*obj)->ori->this[1] = 20;
	(*obj)->ori->this[2] = 20;
	(*obj)->g_scale = 10;
	(*obj)->object_buff = input_parse((*obj)->file);
	(*obj)->vtx_cnt = dl_len((*obj)->object_buff);
	if (verbose == 1)
		printf("\nObject set!\n\n");
}
