/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:59:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/14 18:49:38 by jkoskela         ###   ########.fr       */
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
	t_mtx		*origin;
	t_mtx		*orientation;
	// t_mtx		*view_matrix;
	t_mtx		*out;
	double		translation_vtx[4] = { 0.0, 0.0, 0.0, 1.0};
	double		origin_vtx[4] = { 150.0, 150.0, 80.0, 1.0};
	x = rot_x(fdf->angle_x);
	y = rot_y(fdf->angle_y);
	z = rot_z(fdf->angle_z);
	p = projection(fdf->ratio, fdf->near, fdf->far, fdf->fov);
	t = translation(translation_vtx);
	s = identity(fdf->scale);
	origin = translation(origin_vtx);
	origin = mtx_transpose(origin);
	orientation = rot_x(m_dgr(M_PI));
	out = mtx_multiply(t, x);
	out = mtx_multiply(out, y);
	out = mtx_multiply(out, z);
	out = mtx_multiply(out, s);
	out = mtx_multiply(out, p);
	// view_matrix = mtx_multiply(origin, orientation);
	// out = mtx_multiply(out, view_matrix);
	return (out);
}

t_program		*init(char *file)
{
	t_program *out;

	out = (t_program *)v_alloc(sizeof(t_program));
	out->name = s_dup("fdf");
	out->map = input_parse(out, file);
	out->resx = 1280;
	out->resy = 720;
	out->ratio = out->resx / out->resy;
	out->fov = 60.0;
	out->near = 1.0;
	out->far = 100.0;
	out->scale = 10.0;
	out->angle_x = 0;
	out->angle_y = 0;
	out->angle_z = 0;
	out->transformation_matrix = transformation_matrix(out);
	out->mlx_ptr = mlx_init();
	out->win_ptr = mlx_new_window(out->mlx_ptr, out->resx, out->resy, out->name);
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

// t_mtx			*camera()
// {
// 	double		*org;
// 	double		*dst;
// }
// $this->_origin = $kwargs['origin'];
// 		$v = new Vector ( array( 'dest' => $this->_origin ) );
// 		$this->_tT = new Matrix ( array( 'preset' => Matrix::TRANSLATION, 'vtc' => $v->opposite() ) );
// 		$this->_tR = $kwargs['orientation']->transpose();
// 		$this->_viewMatrix = $this->_tR->mult( $this->_tT );

int				main(int argc, char **argv)
{
	t_program	*fdf;
	t_dlist		*newmap;
	double		*org;
	// double		*dst;

	if (argc != 2)
		argc = 2;
	mtx_tests();
	fdf = init(argv[1]);
	newmap = transform_map(fdf);
	// p_map(&fdf->map);
	// p_str("\n");
	p_map(&newmap);
	// printf("\n%f", fdf->ratio);
	// printf("\n%zu", fdf->map_cols);
	// printf("\n%zu", fdf->map_rows);
	while (newmap)
	{
		org = newmap->content;
		newmap = newmap->next;
		// dst = newmap->content;
		// mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)dst[0], (int)dst[1], 0xFFFFFF);
		// p_dbl_arr(org, 3);
		// while (org[0] <= dst[0] && org[1] <= dst[1])
		// {
		// 	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)org[0], (int)org[1], 0xFFFFFF);
		// 	org[0] = org[0] + 1.0;
		// 	org[1] = org[1] + 1.0;
		// }
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->resx - (int)org[0], fdf->resy - (int)org[1], 0xFFFFFF);
	}
	mlx_loop(fdf->mlx_ptr);
	return(0);
}