/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:33:36 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/10 23:33:46 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vct4			vct4(double x, double y, double z, double w)
{
	t_vct4		out;

	out.x = x;
	out.y = y;
	out.z = z;
	out.w = w;
	return (out);
}
