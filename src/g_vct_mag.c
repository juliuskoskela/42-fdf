/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vct_mag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:45:41 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/04 02:12:14 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double			g_vct_mag(t_vector v)
{
	double	out;

	out = sqrt(pow(v.vct.x, 2) + \
				pow(v.vct.y, 2) + \
				pow(v.vct.z, 2));
	return (out);
}
