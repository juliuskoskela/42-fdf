/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:02:06 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 23:47:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world			add_camera(t_world out, t_camera new, int index, int verbose)
{
	// out.cameras[index] = new;
	out.cam_cnt += 1;
	index = 1;
	new.index = 0;
	if (verbose > 0)
		printf("Camera added!\n\n");
	return (activate_camera(out, index, verbose));
}
