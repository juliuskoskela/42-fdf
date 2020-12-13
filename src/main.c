/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:59:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 20:37:12 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx			*transformation_matrix(t_program *fdf)
{
	t_mtx		*x;
	t_mtx		*y;
	t_mtx		*z;
	t_mtx		*p;
	t_mtx		*t;
	t_mtx		*s;
	t_mtx		*out;
	double		translation_vtx[4] = { 20.0, 20.0, 0.0, 1.0};
	x = rot_x(fdf->angle_x);
	y = rot_y(fdf->angle_y);
	z = rot_z(fdf->angle_z);
	p = projection(fdf->ratio, fdf->near, fdf->far, fdf->fov);
	t = translation(translation_vtx);
	s = identity(fdf->scale);
	out = mtx_multiply(t, x);
	out = mtx_multiply(out, y);
	out = mtx_multiply(out, z);
	out = mtx_multiply(out, s);
	out = mtx_multiply(out, p);
	return (out);
}

t_program		*init(char *file)
{
	t_program *out;

	out = (t_program *)v_alloc(sizeof(t_program));
	out->name = s_dup("fdf");
	out->map = input_parse(file);
	out->resx = 1280;
	out->resy = 720;
	out->ratio = out->resx / out->resy;
	out->fov = 60.0;
	out->near = 1.0;
	out->far = -50.0;
	out->scale = 1.0;
	out->angle_x = -10.0;
	out->angle_y = 0.0;
	out->angle_z = 15.0;
	out->transformation_matrix = transformation_matrix(out);
	return (out);
}

t_dlist			*transform_map(t_program *fdf)
{
	t_dlist		*out;
	t_dlist		*pos;
	double		*tmp;
	double		*vtx;

	out = NULL;
	pos = fdf->map;
	while (pos)
	{
		tmp = pos->content;
		vtx = mtx_vtx(fdf->transformation_matrix, tmp);
		dl_putlast(&out, vtx);
		pos = pos->next;
	}
	return (out);
}

int				main(int argc, char **argv)
{
	t_program	*fdf;
	t_dlist		*newmap;

	if (argc != 2)
		argc = 2;
	mtx_tests();
	fdf = init(argv[1]);
	newmap = transform_map(fdf);
	p_map(&fdf->map);
	p_str("\n");
	p_map(&newmap);
	printf("\n%f", fdf->ratio);
	return(0);
}