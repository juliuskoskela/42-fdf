/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vct_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:24:50 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/04 13:33:18 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vector		g_vct_scale(t_vector v, double scalar)
{
	t_vector	out;
	out.vct.x = v.vct.x * scalar;
	out.vct.y = v.vct.y * scalar;
	out.vct.z = v.vct.z * scalar;
	out.dst.x = out.org.x + out.vct.x;
	out.dst.y = out.org.y + out.vct.y;
	out.dst.z = out.org.z + out.vct.z;
	return (out);
}