/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 02:22:45 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/04 19:35:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_camera		*construct_camera(int verbose)
{
	t_camera	*out;

	out = (t_camera *)v_alloc(sizeof(t_camera));
	out->xyz = (t_mtx **)v_alloc(sizeof(t_mtx *) * 3);
	out->xyz[0] = mtx_new("X", 4, 4);
	out->xyz[1] = mtx_new("Y", 4, 4);
	out->xyz[2] = mtx_new("Z", 4, 4);
	out->pos = mtx_new("p", 1, 3);
	out->ori = mtx_new("o", 1, 3);
	out->ovct = mtx_new("ovct", 1, 5);
	out->rot = mtx_new("R", 4, 4);
	out->tr = mtx_new("tR", 4, 4);
	out->tt = mtx_new("tT", 4, 4);
	out->view_mtx = mtx_new("V", 4, 4);
	out->g_proj = mtx_new("P", 4, 4);
	out->comp = mtx_new("CC", 4, 4);
	if (verbose == 1)
		printf("\nCamera constructed!\n\n");
	return (out);
}
