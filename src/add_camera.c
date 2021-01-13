/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:02:06 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 01:02:10 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world			add_camera(t_world out, t_camera new, int verbose)
{
	out.cameras[out.cam_cnt] = new;
	out.cam_cnt += 1;
	if (verbose > 0)
		printf("Camera added!\n\n");
	return (activate_camera(out, out.cam_cnt - 1, verbose));
}
