/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:50:41 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/04 01:16:41 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			set_camera(t_camera **cam, int verbose)
{
	(*cam)->width = 640;
	(*cam)->height = 480;
	(*cam)->ratio = (*cam)->width / (*cam)->height;
	(*cam)->near = 1.0;
	(*cam)->far = 100.0;
	(*cam)->fov = 60;
	(*cam)->pos->this[0] = 10.0;
	(*cam)->pos->this[1] = 10.0;
	(*cam)->pos->this[2] = 20.0;
	(*cam)->ori->this[0] = 1;
	(*cam)->ori->this[1] = 1;
	(*cam)->ori->this[2] = 1;
	if (verbose == 1)
		printf("\nCamera set!\n\n");
}
