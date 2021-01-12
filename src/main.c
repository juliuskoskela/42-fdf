/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 03:43:04 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/12 18:45:08 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world			proc_wrld_buff(t_world wrld)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < wrld.obj_cnt)
	{
		while (j < wrld.obj_arr[i].vtx_cnt)
		{
			wrld.buffer[k].a = g_mult_vct(wrld.comp, wrld.obj_arr[i].buffer[j].a);
			wrld.buffer[k].b = g_mult_vct(wrld.comp, wrld.obj_arr[i].buffer[j].b);
			wrld.buffer[k].c = g_mult_vct(wrld.comp, wrld.obj_arr[i].buffer[j].c);
			j++;
			k++;
		}
		j = 0;
		i++;
		k++;
	}
	wrld.vtx_cnt = k - 1;
	return (wrld);
}

t_tri		*proc_buff(t_tri *buff, t_tri *ori, t_mtx4 comp, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		buff[i].a = g_mult_vct(comp, ori[i].a);
		buff[i].b = g_mult_vct(comp, ori[i].b);
		buff[i].c = g_mult_vct(comp, ori[i].c);
		i++;
	}
	return (buff);
}

double			get_width(t_vct4 *shape, size_t size)
{
	size_t		i;
	double		out;

	i = 0;
	out = 0;
	while (i < size)
	{
		if (out < shape[i].x)
			out = shape[i].x;
		i++;
	}
	return (out);
}

double			get_height(t_vct4 *shape, size_t size)
{
	size_t		i;
	double		out;

	i = 0;
	out = 0;
	while (i < size)
	{
		if (out < shape[i].y)
			out = shape[i].y;
		i++;
	}
	return (out);
}

double			get_depth(t_vct4 *shape, size_t size)
{
	size_t		i;
	double		out;

	i = 0;
	out = 0;
	while (i < size)
	{
		if (out < shape[i].z)
			out = shape[i].z;
		i++;
	}
	return (out);
}

t_tri			*mesh_grid(t_vct4 *buff, size_t w, size_t size)
{
	t_tri		*out;
	size_t		i;
	size_t		j;
	size_t		k;

	out = (t_tri *)v_alloc(sizeof(t_tri) * size);
	i = 0;
	k = 0;
	j = 0;
	while (i < size - w)
	{
		if (j == w - 1)
		{
			j = 0;
			i++;
		}
		else
		{
			out[k].a = buff[i];
			out[k].b = buff[i + 1];
			out[k].c = buff[i + w];
			out[k + 1].a = buff[i + w + 1];
			out[k + 1].b = buff[i + 1];
			out[k + 1].c = buff[i + w];
			k += 2;
			i++;
			j++;
		}
	}
	return (out);
}

void			print_vct_buff(t_vct4 *buff, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		g_print_vct(buff[i], i);
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_world		wrld;
	t_camera	cam1;
	t_object	mesh;
	int			verbose;

	if (argc < 0)
		return (0);

	verbose = 1;

	mesh.name = s_dup("Mesh");
	mesh.scale = 10;
	mesh = shape_file(mesh, argv[1]);
	mesh.width = get_width(mesh.shape, mesh.vtx_cnt) + 1;
	mesh.height = 0;
	mesh.depth = get_depth(mesh.shape, mesh.vtx_cnt) + 1;
	mesh.tri_cnt = ((mesh.width - 1) * (mesh.depth - 1)) * 2;
	mesh.position = g_vct4(50, 50, 0 , 1);
	mesh.direction = g_vct4(0, 0, 0, 1);
	mesh.comp = comp_model(mesh, verbose);
	mesh.buffer = mesh_grid(mesh.shape, mesh.width, mesh.tri_cnt);
	mesh.buffer = proc_buff(mesh.buffer, mesh.buffer, mesh.comp, mesh.tri_cnt);

	cam1.name = s_dup("Camera 1");
	cam1.ratio = RESX / RESY;
	cam1.near = 1;
	cam1.far = 1000;
	cam1.fov = 60;
	cam1.position = g_vct4(0, 100, 0, 1);
	cam1.direction = g_vct4(45, 0, 0, 1);
	cam1.view = comp_view(cam1, verbose);
	cam1.projection = g_proj(cam1.fov, cam1.ratio, cam1.near, cam1.far);

	wrld.mlx_ptr = mlx_init();
	wrld.win_ptr = mlx_new_window(wrld.mlx_ptr, RESX, RESY, "fdf");
	if (!(wrld.buffer = (t_tri *)v_alloc(sizeof(t_tri) * MAX_BUFF)))
		error("Malloc failure.");
	wrld.comp = g_mult_mtx(cam1.view, cam1.projection);
	wrld.buffer = proc_buff(wrld.buffer, mesh.buffer, wrld.comp, mesh.tri_cnt);
	render(wrld.buffer, wrld.mlx_ptr, wrld.win_ptr, mesh.tri_cnt);
	mlx_loop(wrld.mlx_ptr);
	return (0);
}








// int				main(void)
// {
// 	t_world		*wrld;
// 	t_camera	*cam1;
// 	t_object	*obj1;
// 	t_mtx		*comp;
// 	int			verbose;

// 	// argc = 0;
// 	verbose = 2;
// 	comp = mtx_new("C", 4, 4);
// 	wrld = construct_world(verbose);
// 	cam1 = construct_camera(verbose);
// 	obj1 = construct_object(verbose);

// 	set_world(wrld, verbose);
// 	set_camera(cam1, verbose);
// 	cube(obj1);
// 	cam1.watch[0] = obj1.pos.this[0];
// 	cam1.watch[1] = obj1.pos.this[1];
// 	cam1.watch[2] = obj1.pos.this[2];
// 	// set_object(obj1, argv[1], verbose);

// 	comp_model(obj1, verbose);
// 	comp_camera(cam1, verbose);

// 	// wrld.wrld_vtx_buff = obj1.obj_vtx_buff;
// 	// wrld.wrld_tri_buff = obj1.obj_tri_buff;

// 	mtx_multiply(comp, cam1.comp, obj1.comp);
// 	proc_zbuff(obj1.zbuff, comp, 8, verbose);
// 	print_zbuff(obj1.zbuff, 8, verbose);
// 	wrld.zbuff = obj1.zbuff;
// 	wrld.size = 8;
// 	// proc_buff(wrld.wrld_vtx_buff, comp, verbose);
// 	// print_tri(obj1.obj_tri_buff);
// 	render(wrld);
// 	mlx_loop(wrld.mlx_ptr);
// 	return (0);
// }

// void			cube(t_object *obj)
// {
// 	obj.buffer[0] = vct4(1, 0, 0, 1);
// 	obj.buffer[1] = vct4(1, 1, 0, 1);
// 	obj.buffer[2] = vct4(1, 1, 1, 1);
// 	obj.buffer[3] = vct4(0, 1, 1, 1);
// 	obj.buffer[4] = vct4(0, 0, 1, 1);
// 	obj.buffer[5] = vct4(0, 0, 0, 1);
// 	obj.buffer[6] = vct4(1, 0, 1, 1);
// 	obj.buffer[7] = vct4(0, 1, 0, 1);
// 	obj.vtx_cnt = 8;
// 	obj.pos.this[0] = 100;
// 	obj.pos.this[1] = 100;
// 	obj.pos.this[2] = 0;
// 	obj.ori.this[0] = -30;
// 	obj.ori.this[1] = 20;
// 	obj.ori.this[2] = 0;
// 	obj.g_scale = 100;
// }

// void			proc_zbuff(t_mtx **zbuff, t_mtx *comp, size_t size, int verbose)
// {
// 	t_mtx		*alloc;
// 	size_t		i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		alloc = mtx_new("n", 1, 4);
// 		mtx_multiply(alloc, comp, zbuff[i]);
// 		zbuff[i] = alloc;
// 		i++;
// 	}
// 	if (verbose > 0)
// 		printf("Buffer processed!\n\n");
// }

// void			print_zbuff(t_mtx **zbuff, size_t size, int verbose)
// {
// 	size_t		i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		mtx_print(zbuff[i]);
// 		i++;
// 	}
// 	if (verbose > 0)
// 		printf("Buffer processed!\n\n");
// }