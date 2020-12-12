/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rot_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:19:33 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/12 04:19:35 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_matrix		*mtx_rot_z(double angle)
{
	t_matrix	*out;

	out = mtx_id(1);
	out->mx->x = cos(angle);
	out->my->x = -sin(angle);
	out->mx->z = sin(angle);
	out->my->z = cos(angle);
	out->mz->z = 1;
	return (out);
}
