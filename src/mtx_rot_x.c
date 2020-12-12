/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rot_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:18:50 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/12 04:18:51 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_matrix		*mtx_rot_x(double angle)
{
	t_matrix	*out;

	out = mtx_id(1);
	out->mx->x = 1;
	out->my->y = cos(angle);
	out->my->z = -sin(angle);
	out->mz->y = sin(angle);
	out->mz->z = cos(angle);
	return (out);
}
