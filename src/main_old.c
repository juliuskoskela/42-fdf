/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_old.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:59:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/14 23:42:19 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

typedef struct	s_object
{
	t_mtx		*(*rotation)(double, double, double);
	t_mtx		*(*scale)(size_t);
	t_mtx		*(*translation)(double *);
	double		*position;
}				t_object;

typedef struct	s_world
{
	t_mtx		*(*projection)(double, double, double, double);
}				t_world;

typedef struct	s_camera
{
	double		*origin;
	t_mtx		*orientation;
	t_mtx		*(*view_mtx)(double *, double, double, double);
}				t_camera;

t_mtx			*rotation(double o_x, double o_y, double o_z)
{
	t_mtx		*out;

	out = rot_x(o_x);
	out = mtx_multiply(out, rot_y(o_y));
	out = mtx_multiply(out, rot_z(o_z));
	return (out);
}

double			vct_magnitude(double *vct)
{
	return (sqrt(pow(vct[0], 2) + pow(vct[1], 2) + pow(vct[2], 2)));
}

double			*vct_opposite(double *vct)
{
	double		*out;
	double		mag;

	mag = -1 * vct_magnitude(vct);
	out = vtx_new(vct[0] / mag, vct[1] / mag, vct[2] / mag, 1.0, 0);
	return (out);
}

t_mtx			*view_mtx(double *origin, double o_x, double o_y, double o_z)
{
	t_mtx		*out;

	out = rotation(o_x, o_y, o_z);
	out = mtx_multiply(out, mtx_transpose(translation(vct_opposite(origin))));
	return (out);
}

t_mtx			*transformation_matrix(t_program *fdf)
{
	t_mtx		*x;
	t_mtx		*y;
	t_mtx		*z;
	t_mtx		*p;
	t_mtx		*t;
	t_mtx		*s;
	t_mtx		*view_matrix;
	t_mtx		*out;
	double		translation_vtx[4] = { 20.0, 20.0, 0.0, 1.0};
	double		view_origin[4] = { 150.0, 150.0, 80.0, 1.0};
	x = rot_x(fdf->angle_x);
	y = rot_y(fdf->angle_y);
	z = rot_z(fdf->angle_z);
	p = projection(fdf->ratio, fdf->near, fdf->far, fdf->fov);
	t = translation(translation_vtx);
	s = identity(fdf->scale);
	origin = translation(view_origin);
	origin = mtx_transpose(origin);
	orientation = rot_x(m_dgr(M_PI));
	out = mtx_multiply(t, x);
	out = mtx_multiply(out, y);
	out = mtx_multiply(out, z);
	out = mtx_multiply(out, s);
	out = mtx_multiply(out, p);
	view_matrix = view_mtx(view_origin, m_dgr(M_PI), 0.0, 0.0);
	out = mtx_multiply(out, view_matrix);
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
	out->far = 1000.0;
	out->scale = 20.0;
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

void			drawline(t_program *fdf, double *org, double *dst)
{
	// -5, 10	10, 5
	int			org_x;
	int			org_y;
	int			dst_x;
	int			dst_y;


	org_x = org[0];
	dst_x = dst[0];
	org_y = org[1];
	dst_y = dst[1];
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->resx / 2 - (int)org[0], fdf->resy / 2 - (int)org[1], org[3]);
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->resx / 2 - (int)dst[0], fdf->resy / 2 - (int)dst[1], 0xFFFFFF);
	while (org_x <= dst_x && org_y <= dst_y)
	{
		// mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->resx / 2 - org_x, fdf->resy / 2 - org_y, 0xFFFFFF);
		org_x++;
		org_y++;
	}
}
void			render(t_program *fdf)
{
	double		*org;
	// double		*dst;

	while (fdf->map->next)
	{
		org = fdf->map->content;
		fdf->map = fdf->map->next;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->resx / 2 - (int)org[0], fdf->resy / 2 - (int)org[1], 0xFFFFFF - (org[4]));
		// drawline(fdf, org, dst);
	}
	mlx_loop(fdf->mlx_ptr);
}
int				main(int argc, char **argv)
{
	t_program	*fdf;
	// t_dlist		*newmap;

	if (argc != 2)
		argc = 2;
	// mtx_tests();
	fdf = init(argv[1]);
	fdf->map = transform_map(fdf);
	// p_map(&fdf->map);
	// p_str("\n");
	// p_map(&newmap);
	// printf("\n%f", fdf->ratio);
	// printf("\n%zu", fdf->map_cols);
	// printf("\n%zu", fdf->map_rows);
	render(fdf);
	return(0);
}