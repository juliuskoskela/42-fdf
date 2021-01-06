/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 03:43:04 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 22:21:37 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// t_mtx			*mtx_dup(t_mtx *mtx)
// {
// 	t_mtx		*out;
// 	int			i;

// 	i = 0;
// 	out = (s_join("d", mtx->name), 4, 4);
// 	while (i < out->x * out->y)
// 	{
// 		out->this[i] = mtx->this[i];
// 		i++;
// 	}
// 	return (out);
// }

int				main(int argc, char **argv)
{
	t_world		*wrld;
	t_camera	*cam1;
	t_object	*obj1;
	t_mtx		*comp;
	int			verbose;

	argc = 0;
	verbose = 2;
	comp = mtx_new("C", 4, 4);
	wrld = construct_world(verbose);
	cam1 = construct_camera(verbose);
	obj1 = construct_object(verbose);

	set_world(wrld, verbose);
	set_camera(cam1, verbose);
	set_object(obj1, argv[1], verbose);

	comp_object(obj1, verbose);
	comp_camera(cam1, verbose);

	wrld->wrld_vtx_buff = obj1->obj_vtx_buff;
	wrld->wrld_tri_buff = obj1->obj_tri_buff;

	mtx_multiply(comp, cam1->comp, obj1->comp);
	proc_buff(wrld->wrld_vtx_buff, comp, verbose);
	print_tri(obj1->obj_tri_buff);
	render(wrld);
	mlx_loop(wrld->mlx_ptr);
	return (0);
}
