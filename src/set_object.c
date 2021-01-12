/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:51:41 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/10 23:01:44 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void			print_method(t_object *obj, int verbose)
{
	if (verbose == 2)
	{
		printf("obj->pos[0] = %f\n", obj->pos->this[0]);
		printf("obj->pos[1] = %f\n", obj->pos->this[1]);
		printf("obj->pos[2] = %f\n", obj->pos->this[2]);
		printf("obj->ori[0] = %f\n", obj->ori->this[0]);
		printf("obj->ori[1] = %f\n", obj->ori->this[1]);
		printf("obj->ori[2] = %f\n", obj->ori->this[2]);
		printf("obj->scale  = %f\n", obj->g_scale);
		printf("obj->file   = %s\n", obj->file);
	}
	printf("\nObject set!\n\n");
}


void			set_object(t_object *obj, char *file, int verbose)
{

	obj->pos->this[0] = 0;
	obj->pos->this[1] = 0;
	obj->pos->this[2] = 0;
	obj->ori->this[0] = 0;
	obj->ori->this[1] = 0;
	obj->ori->this[2] = 0;
	obj->g_scale = 40;
	obj->file = file;
	obj->obj_vtx_buff = input_parse(obj);
	obj->obj_tri_buff = map_vtx_tri(obj->obj_vtx_buff, obj->x);
	if (verbose > 0)
		print_method(obj, verbose);
}
