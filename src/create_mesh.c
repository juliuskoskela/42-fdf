/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:00:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 23:13:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_object		create_mesh(char *file, char *name, int verbose)
{
	t_object	out;

	out.name = name;
	out.scale = 10;
	out = shape_file(out, file);
	out.dimensions = get_mesh_dimensions(out.shape, out.vtx_cnt);
	out.tri_cnt = ((out.dimensions.x - 1) * (out.dimensions.z - 1)) * 2;
	out.position = g_vct4(50, 50, 0, 1);
	out.direction = g_vct4(0, 0, 0, 1);
	out.buffer = allocate_buffer(out.tri_cnt);
	out.buffer = grid_triangulation(out.buffer, out.shape, \
	out.dimensions.x, out.tri_cnt);
	out.model_mtx = compose_model(out, verbose);
	out.buffer = process_buffer(out.buffer, out.buffer, \
	out.model_mtx, out.tri_cnt);
	if (verbose > 0)
		printf("Mesh created!\n\n");
	return (out);
}
