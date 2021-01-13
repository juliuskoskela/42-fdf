/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 03:43:04 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 02:05:46 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		check_arguments(int argc, char **argv)
{
	if (argc < 0)
		error("Too few arguments.\n");
	if (argv[1])
		printf("Arg 1 ok!\n");
}

int				main(int argc, char **argv)
{
	t_world		wrld;
	t_camera	cam1;
	t_object	mesh;
	int			verbose;

	verbose = 0;
	check_arguments(argc, argv);
	mesh = create_mesh(argv[1], "Mesh 1", verbose);
	cam1 = create_camera("Camera 1", verbose);
	wrld = create_world("Space", verbose);
	wrld = add_camera(wrld, cam1, verbose);
	wrld = add_object(wrld, mesh, verbose);
	wrld = process_world(wrld, verbose);
	wrld.mlx_ptr = mlx_init();
	wrld.win_ptr = mlx_new_window(wrld.mlx_ptr, RESX, RESY, wrld.name);
	mlx_key_hook(wrld.win_ptr, key_callback, &wrld);
	render(wrld);
	mlx_loop(wrld.mlx_ptr);
	return (0);
}
