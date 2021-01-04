/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 03:43:04 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/04 05:58:32 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int				main(int argc, char **argv)
{
	t_world		*wrld;
	t_camera	*cam1;
	t_object	*obj1;
	size_t		i;
	int			verbose;

	if (argc == 0)
		return (0);
	verbose = 1;
	i = 0;
	wrld = construct_world(verbose);
	cam1 = construct_camera(verbose);
	obj1 = construct_object(s_dup(argv[1]), verbose);
	set_world(&wrld, verbose);
	set_camera(&cam1, verbose);
	set_object(&obj1, verbose);
	comp_object(&obj1, verbose);
	comp_camera(&cam1, verbose);
	mtx_multiply(wrld->comp, cam1->comp, obj1->comp);
	wrld->obj_arr[0] = obj1;
	wrld->obj_cnt = 1;

	wrld->wrld_prebuff = obj1->object_buff;
	wrld->buffsize = obj1->vtx_cnt;
	process_world_buffer(&wrld, verbose);
	render(&wrld, wrld->wrld_buff, wrld->buffsize);
	mlx_loop(wrld->mlx_ptr);
	return (0);
}

// static void		print_method(t_camera *cam)
// {
// 	printf("## proj_mtx matrix\n\n");
// 	printf("We create a proj_mtx matrix to get a 2D representation.\n\n");
// 	printf("#### proj_mtx variables\n\n");
// 	printf("\\( ratio = %.2f \\) \n", cam->ratio);
// 	printf("\\( near = %.2f \\) \n", cam->near);
// 	printf("\\( far = %.2f \\) \n", cam->far);
// 	printf("\\( fov = %.2f\\degree \\) \n\n", cam->fov);
// 	printf("\\( P = (p_5 = 1 / tan(0.5 * fov)) + (p_0 = p_5 / ratio) + (p_10 = -1 * (-near - far) / (near - far)) + (p_11 = (2 * near * far) / (near - far)) + (p_14 = -1) + (p_15 = 0)) \\) \n\n");
// 	mtx_print(cam->proj_mtx);
// }
