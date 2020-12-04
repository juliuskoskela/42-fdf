/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vct_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:44:24 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/04 02:12:20 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vector		g_vct_sub(t_vector a, t_vector b)
{
	t_vector	out;

	out.dst.x = a.dst.x - b.dst.x;
	out.dst.y = a.dst.y - b.dst.y;
	out.dst.z = a.dst.z - b.dst.z;
	return (out);
}
