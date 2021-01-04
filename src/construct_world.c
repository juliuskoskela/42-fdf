/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 14:48:51 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/04 04:31:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world			*construct_world(int verbose)
{
	t_world		*out;

	out = (t_world *)v_alloc(sizeof(t_world));
	out->obj_arr = (t_object **)v_alloc(sizeof(t_object *) * 10);
	out->cam_arr = (t_camera **)v_alloc(sizeof(t_camera *) * 10);
	out->wrld_buff = (t_mtx **)v_alloc(sizeof(t_mtx *) * MAX_BUFF);
	out->comp = mtx_new("CW", 4, 4);
	if (verbose == 1)
		printf("\nWorld constructed!\n\n");
	return (out);
}
