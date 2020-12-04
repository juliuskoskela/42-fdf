/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vct_cross.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:46:17 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/04 13:56:14 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vector		g_vct_cross(t_vector a, t_vector b)
{
	t_vector	out;
	out.vct.x = a.vct.y * b.vct.z - a.vct.z * b.vct.y;
	out.vct.y = a.vct.z * b.vct.x - a.vct.x * b.vct.z;
	out.vct.z = a.vct.x * b.vct.y - a.vct.y * b.vct.x;
	return (out);
}