/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vertex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:41:08 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/04 02:12:27 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vertex		g_vertex(double x, double y, double z)
{
	t_vertex	out;

	out.x = x;
	out.y = y;
	out.z = z;
	out.w = 1.0;
	return (out);
}
