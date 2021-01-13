/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 03:43:04 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 23:45:21 by jkoskela         ###   ########.fr       */
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
	t_object	mesh;
	int			verbose;

	verbose = 0;
	check_arguments(argc, argv);
	mesh = create_mesh(argv[1], "Mesh 1", verbose);
	wrld = create_world("Space", verbose);
	wrld = add_object(wrld, mesh, verbose);
	wrld = process_world(wrld, verbose);
	render(wrld);
	return (0);
}
