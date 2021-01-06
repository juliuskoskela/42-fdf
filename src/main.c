/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 03:43:04 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 04:54:48 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int				main(int argc, char **argv)
{
	t_world		*wrld;
	t_camera	*cam1;
	t_object	*obj1;
	int			verbose;

	argc = 0;
	verbose = 2;

	wrld = construct_world(verbose);
	cam1 = construct_camera(verbose);
	obj1 = construct_object(s_dup(argv[1]), verbose);

	set_world(&wrld, verbose);
	set_camera(&cam1, verbose);
	set_object(&obj1, verbose);

	comp_object(obj1, verbose);
	comp_camera(&cam1, verbose);

	proc_buff(obj1->obj_vtx_buff, obj1->comp, verbose);
	wrld->wrld_vtx_buff = obj1->obj_vtx_buff;
	wrld->wrld_tri_buff = obj1->obj_tri_buff;
	proc_buff(wrld->wrld_vtx_buff, cam1->comp, verbose);
	print_tri(obj1->obj_tri_buff);
	render(&wrld);
	mlx_loop(wrld->mlx_ptr);
	return (0);
}
