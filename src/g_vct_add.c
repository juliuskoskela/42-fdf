/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vct_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:45:18 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/04 21:21:00 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vector		g_vct_add(t_vector a, t_vector b)
{
	t_vector	out;

	out.vct.x = a.vct.x + b.vct.x;
	out.vct.y = a.vct.y + b.vct.y;
	out.vct.z = a.vct.z + b.vct.z;
	return (out);
}
