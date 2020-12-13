/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 10:18:24 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 19:30:55 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int				mtx_tests(void)
{
	t_mtx		*x;
	t_mtx		*y;
	t_mtx		*z;
	t_mtx		*p;
	t_mtx		*t;
	t_mtx		*s;
	t_mtx		*m;
	double		ratio = 1.333;
	double		near = 1.0;
	double		far = -50.0;
	double		scale = 10.0;
	double		fov = 60.0;
	double		ax = PI / 4;
	double		ay = PI / 2;
	double		az = 2 * PI;
	double		translation_vtx[4] = { 20.0, 20.0, 0.0, 1.0};
	double		vtx[4] = { 1.0, 1.0, 0.0, 1.0};
	x = rot_x(ax);
	y = rot_y(ay);
	z = rot_z(az);
	p = projection(ratio, near, far, fov);
	t = translation(translation_vtx);
	s = identity(scale);
	m = mtx_multiply(t, x);
	m = mtx_multiply(m, y);
	m = mtx_multiply(m, s);
	double		*transformed_vtx = mtx_vtx(m, vtx);
	printf("\n");
	mtx_print(x);
	printf("\n");
	mtx_print(y);
	printf("\n");
	mtx_print(z);
	printf("\n");
	mtx_print(p);
	printf("\n");
	mtx_print(t);
	printf("\n");
	mtx_print(s);
	printf("\n");
	mtx_print(m);
	printf("\nTransformed vertex: ");
	p_dbl_arr(transformed_vtx, 4);
	printf("\nTest dgr->rad: %f", m_rad(60));
	printf("\nTest rad->dgr: %f\n\n", m_dgr(m_rad(60)));
	return (0);
}
