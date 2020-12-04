/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vct_dot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:29:22 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/04 13:43:09 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double			g_vct_dot(t_vector a, t_vector b)
{
	double	out;

	out = a.vct.x * b.vct.x + \
			a.vct.y * b.vct.y + \
			a.vct.z * b.vct.z;
	return (out);
}
