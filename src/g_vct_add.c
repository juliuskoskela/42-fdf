/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vct_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:45:18 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/04 02:12:05 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vector		g_vct_add(t_vector a, t_vector b)
{
	t_vector	out;

	out.vct.x = a.vct.x + b.vct.x;
	out.vct.y = a.vct.y + b.vct.y;
	out.vct.z = a.vct.z + b.vct.z;

	out.dst.x = out.org.x + out.vct.x;
	out.dst.y = out.org.y + out.vct.y;
	out.dst.z = out.org.z + out.vct.z;
	return (out);
}
