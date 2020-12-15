/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:59:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/15 02:42:54 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

t_mtx			*view_mtx(double *pos, double *rot)
{
	t_mtx		*out;

	out = rotation(rot[0], rot[1], rot[2]);
	out = mtx_multiply(out, mtx_transpose(translation(vct_opposite(pos))));
	return (out);
}

t_mtx			*object_mtx(t_mtx *rot, t_mtx *scale, t_mtx *move)
{
	return (mtx_multiply(rot, mtx_multiply(scale, move)));
}

void			transform(t_dlist *verteces, t_mtx *object_mtx)
{
	t_dlist		*pos;
	double		*tmp;

	pos = verteces;
	while (pos)
	{
		tmp = pos->content;
		pos->content = (void *)mtx_vtx(object_mtx, tmp);
		pos = pos->next;
	}
}

t_camera		*construct_camera()
{
	t_camera	*out;

	out = (t_camera *)v_alloc(sizeof(t_camera));
	out->position = NULL;
	out->rotation = NULL;
	out->ratio = 0.0;
	out->near = 0.0;
	out->far = 0.0;
	out->fov = 0.0;
	out->view_mtx = &view_mtx;
	return (out);
}


t_world			*construct_world()
{
	t_world		*out;

	out = (t_world *)v_alloc(sizeof(t_world));
	out->obj_cnt = 0.0;
	out->resy = 0.0;
	out->resy = 0.0;
	out->camera = NULL;
	out->world_buffer = NULL;
	out->projection = &projection;
	return (out);
}

t_object		*construct_object(t_dlist *object_buffer)
{
	t_object	*out;

	out = (t_object *)v_alloc(sizeof(t_object));
	out->scalar = 1.0;
	out->position = NULL;
	out->rotation = NULL;
	out->object_buffer = object_buffer;
	out->rotate = &rotation;
	out->scale = &identity;
	out->move = &translation;
	out->object_mtx = &object_mtx;
	out->transform = &transform;
	return (out);
}

t_program			*init(char *file)
{
	t_mtx			*tmp;
	t_object		*obj_1;
	t_camera		*camera;
	t_world			*world;
	t_program		*out;

/*
**	Initialize object:
*/
	obj_1 = construct_object(input_parse(file));
	obj_1->scalar = 10.0;
	obj_1->position = vtx_new(20, 20, 80, 1, 0);
	obj_1->rotation = vtx_new(15, 0, 0, 0, 0);
	obj_1->trans_mtx = obj_1->object_mtx(obj_1->rotate(15, 0, 0), obj_1->scale(obj_1->scalar), obj_1->move(obj_1->position));
	obj_1->transform(obj_1->object_buffer, obj_1->trans_mtx);
/*
**	Initialize camera:
*/
	camera = construct_camera();
	camera->far = 1.0;
	camera->near = 1000.0;
	camera->ratio = 1280 / 720;
	camera->fov = 60;
	camera->position = vtx_new(0, 0, 0, 1, 0);
	camera->rotation = vtx_new(m_dgr(M_PI), 0, 0, 1, 0);;
/*
**	Initialize world:
*/
	world = construct_world();
	world->obj_cnt = 1;
	world->resy = 0.0;
	world->resy = 0.0;
	world->camera = NULL;
	world->world_buffer = (t_object **)v_alloc(sizeof(t_object *) * world->obj_cnt);
	world->world_buffer[0] = obj_1;
/*
**	Initialize program:
*/
	out = (t_program *)v_alloc(sizeof(t_program));
	out->name = s_dup("fdf");
	out->world = world;
	out->world->obj_cnt = 1;
	out->world->camera = camera;
	out->world->world_buffer[0] = obj_1;
	return (out);
}

int				main(int argc, char **argv)
{
	t_program	*fdf;

	if (argc != 2)
		argc = 2;
	fdf = init(argv[1]);
	return(0);
}










// void			render(t_program *fdf)
// {
// 	double		*org;
// 	// double		*dst;

// 	while (fdf->map->next)
// 	{
// 		org = fdf->map->content;
// 		fdf->map = fdf->map->next;
// 		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->resx / 2 - (int)org[0], fdf->resy / 2 - (int)org[1], 0xFFFFFF - (org[4]));
// 	}
// 	mlx_loop(fdf->mlx_ptr);
// }


// t_mtx			*transformation_matrix(t_program *fdf)
// {
// 	t_camera	*cam;
// 	t_object	*obj;
// 	t_world		*wld;
// 	cam = construct_camera();
// 	cam->position = vtx_new(150.0, 150.0, 80.0, 1.0, 0x00);
// 	cam->rotation = vtx_new(m_dgr(M_PI), 0.0, 0.0, 1.0, 0x00);
// 	return (0);
// }