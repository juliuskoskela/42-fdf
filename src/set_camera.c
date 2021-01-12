/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:50:41 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/10 23:01:15 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void			print_method(t_camera *cam, int verbose)
{
	if (verbose == 2)
	{
		printf("cam->pos[0] = %f\n", cam->pos->this[0]);
		printf("cam->pos[1] = %f\n", cam->pos->this[1]);
		printf("cam->pos[2] = %f\n", cam->pos->this[2]);
		printf("cam->ori[0] = %f\n", cam->ori->this[0]);
		printf("cam->ori[1] = %f\n", cam->ori->this[1]);
		printf("cam->ori[2] = %f\n", cam->ori->this[2]);
		printf("cam->ratio  = %f\n", cam->ratio);
		printf("cam->near   = %f\n", cam->near);
		printf("cam->far    = %f\n", cam->far);
		printf("cam->fov    = %f\n", cam->fov);
	}
	printf("\nObject set!\n\n");
}

void			set_camera(t_camera *cam, int verbose)
{
	cam->ratio = (double)RESX / (double)RESY;
	cam->near = 1.0;
	cam->far = 1000.0;
	cam->fov = 60;
	cam->pos->this[0] = 100;
	cam->pos->this[1] = 100;
	cam->pos->this[2] = 100;
	cam->ori->this[0] = 0;
	cam->ori->this[1] = 0;
	cam->ori->this[2] = 0;
	if (verbose > 0)
		print_method(cam, verbose);
}
