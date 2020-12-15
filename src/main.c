/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:59:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/15 06:19:17 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			render(t_program *fdf)
{
	t_dlist		*tmp;
	double		*org;
	void		*mlx_ptr = mlx_init();
	void		*win_ptr = mlx_new_window(mlx_ptr, fdf->world->resx, fdf->world->resy, fdf->name);

	tmp = fdf->world->world_buffer[0]->object_buffer;
	while (tmp)
	{
		org = tmp->content;
		mlx_pixel_put(mlx_ptr, win_ptr, (int)org[0], (int)org[1], 0xFFFFFF - (org[4]));
		tmp = tmp->next;
	}
	mlx_key_hook(p.win_ptr, key_callback, &p);
	mlx_loop(mlx_ptr);
}

int				main(int argc, char **argv)
{
	t_program	*fdf;
	t_object	*obj_1;

	if (argc != 2)
		argc = 2;
	fdf = construct_program();

	obj_1 = construct_object(input_parse(argv[1]));
	obj_1->scalar = 10.0;
	obj_1->pos = vtx_new(100, 100, 100, 1, 0);
	obj_1->rot = vtx_new(180, 0, 0, 1, 0);
	obj_1->xyz = obj_1->rotate(obj_1->rot);
	obj_1->mov = obj_1->move(obj_1->pos);
	obj_1->scl = obj_1->scale(obj_1->scalar);
	obj_1->cmp = obj_1->object_cmp(obj_1->xyz, obj_1->mov, obj_1->scl);
	obj_1->transform(obj_1->object_buffer, obj_1->cmp);

	fdf->world->obj_cnt = 1;
	fdf->world->world_buffer = (t_object **)v_alloc(sizeof(t_object *) * fdf->world->obj_cnt);
	fdf->world->resy = 720;
	fdf->world->resx = 1280;
	fdf->world->world_buffer[0] = obj_1;

	fdf->world->camera->ratio = fdf->world->resx / fdf->world->resy;
	fdf->world->camera->near = 1.0;
	fdf->world->camera->far = 1000.0;
	fdf->world->camera->fov = 60;
	fdf->world->camera->pos = vtx_new(10, 10, 10, 1, 0);
	fdf->world->camera->rot = vtx_new(0, 0, 0, 1, 0);
	fdf->world->camera->view = fdf->world->camera->view_mtx(fdf->world->camera->pos, fdf->world->camera->rot);
	fdf->world->camera->proj = fdf->world->camera->projection(fdf->world->camera->ratio, fdf->world->camera->near, fdf->world->camera->far, fdf->world->camera->fov);
	fdf->world->camera->cmp = mtx_multiply(fdf->world->camera->proj, fdf->world->camera->view);
	mtx_print(fdf->world->camera->view);
	mtx_print(fdf->world->camera->proj);
	mtx_print(fdf->world->camera->cmp);

	fdf->world->transform(fdf->world->world_buffer[0]->object_buffer, fdf->world->camera->cmp);
	p_map(&fdf->world->world_buffer[0]->object_buffer);
	render(fdf);
	return(0);
}
