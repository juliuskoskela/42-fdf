/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:47:51 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/02 01:18:48 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			destruct_camera(t_camera *cam, int verbose)
{
	free(cam->pos);
	free(cam->ori);
	mtx_free(cam->ovct);
	mtx_free(cam->rot);
	mtx_free(cam->tr);
	mtx_free(cam->tt);
	mtx_free(cam->view_mtx);
	mtx_free(cam->proj_mtx);
	mtx_free(cam->comp);
	mtx_free(cam->xyz[0]);
	mtx_free(cam->xyz[1]);
	mtx_free(cam->xyz[2]);
	free(cam->xyz);
	free(cam);
	if (verbose == 1)
		printf("\nCamera destructed!\n\n");
}
