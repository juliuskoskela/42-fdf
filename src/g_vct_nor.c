/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vct_nor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:39:54 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/04 02:12:17 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vector		g_vct_nor(t_vector v)
{
	t_vector	out;
	t_vertex	tmp;
	double		mag;

	mag = g_vct_mag(v);
	out.vct.x = v.vct.x / mag;
	out.vct.y = v.vct.y / mag;
	out.vct.z = v.vct.z / mag;

	out.dst.x = out.org.x + out.vct.x;
	out.dst.y = out.org.y + out.vct.y;
	out.dst.z = out.org.z + out.vct.z;
	return (out);
}
