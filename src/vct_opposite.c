/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_opposite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 02:46:49 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/15 02:46:50 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double			*vct_opposite(double *vct)
{
	double		*out;
	double		mag;

	mag = -1 * vct_magnitude(vct);
	out = vtx_new(vct[0] / mag, vct[1] / mag, vct[2] / mag, 1.0, 0);
	return (out);
}
