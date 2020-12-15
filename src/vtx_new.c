/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtx_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:23:38 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/14 20:39:18 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double			*vtx_new(double x, double y, double z, double w, double c)
{
	double		*out;
	out = (double *)v_alloc(sizeof(double) * 5);
	out[0] = x;
	out[1] = y;
	out[2] = z;
	out[3] = w;
	out[4] = c;
	return (out);
}
