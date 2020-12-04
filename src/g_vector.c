/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:40:34 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/04 02:12:23 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vector		g_vector(t_vertex org, t_vertex dst)
{
	t_vector	out;

	out.org = org;
	out.dst = dst;
	out.vct = g_vertex(dst.x - org.x, dst.y - org.y, dst.z - org.z);
	return (out);
}
