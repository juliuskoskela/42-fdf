/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:50:41 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 04:51:42 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			set_camera(t_camera **cam, int verbose)
{
	(*cam)->width = RESX;
	(*cam)->height = RESY;
	(*cam)->ratio = (*cam)->width / (*cam)->height;
	(*cam)->near = 1.0;
	(*cam)->far = 1000.0;
	(*cam)->fov = 60;
	(*cam)->pos->this[0] = 0;
	(*cam)->pos->this[1] = 0;
	(*cam)->pos->this[2] = 0;
	(*cam)->ori->this[0] = 0;
	(*cam)->ori->this[1] = 0;
	(*cam)->ori->this[2] = 0;
	if (verbose > 0)
		printf("\nCamera set!\n\n");
}
