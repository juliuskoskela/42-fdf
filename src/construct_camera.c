/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 02:51:28 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/15 05:51:01 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_camera		*construct_camera()
{
	t_camera	*out;

	out = (t_camera *)v_alloc(sizeof(t_camera));
	out->pos = NULL;
	out->rot = NULL;
	out->ratio = 0.0;
	out->near = 0.0;
	out->far = 0.0;
	out->fov = 0.0;
	out->view_mtx = &view_mtx;
	out->projection = &projection;
	return (out);
}
