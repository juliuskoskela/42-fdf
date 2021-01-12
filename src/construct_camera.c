/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 02:22:45 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/11 03:29:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_camera		*construct_camera(double ratio, int near, int far, int fov)
{
	t_camera	*out;

	out = (t_camera *)v_alloc(sizeof(t_camera));
	out->ratio = ratio;
	out->near = near;
	out->far = far;
	out->fov = fov;
	return (out);
}
