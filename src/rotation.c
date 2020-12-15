/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 02:44:41 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/15 04:26:50 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx			*rotation(double *rot)
{
	t_mtx		*out;

	out = rot_x(rot[0]);
	out = mtx_multiply(out, rot_y(rot[1]));
	out = mtx_multiply(out, rot_z(rot[2]));
	return (out);
}
