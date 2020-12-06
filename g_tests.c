/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:47:11 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/06 06:07:57 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			main(void)
{
	t_vertex	org = g_vertex(0.0, 0.0, 0.0);
	t_vertex	dst = g_vertex(2.0, 3.0, 5.0);
	t_vector	vct = g_vector(org, dst);
	t_vector	nor = g_vct_nor(vct);
	double		nor_mag = g_vct_mag(nor);
	printf("x = %f\ny = %f\nz = %f\n", vct.vct.x, vct.vct.y, vct.vct.z);
	printf("x = %f\ny = %f\nz = %f\n", nor.dst.x, nor.dst.y, nor.dst.z);
	printf("nor_mag: %f\n", nor_mag);
}

// A + B = (Ax + Bx) * i + (Ay + By) * j + (Az + Bz) * k

