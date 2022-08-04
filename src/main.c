/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 03:43:04 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 04:07:17 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

const char *usage =
"usage:	./fdf [map_file]\n\n\
	--verbose: Verbose printing on stdout\n";

int main(int argc, char **argv)
{
	t_model		model_1;
	t_camera	cam_0;
	t_world		world;

	g_verbose = 0;
	if (argc > 3
		|| argc < 2
		|| s_cmp(argv[1], "--help") == 0)
	{
		p_str(usage);
		return (-1);
	}
	if (s_cmp(argv[2], "--verbose") == 0)
		g_verbose = 1;
	model_1 = create_model(0);
	parse_file(&model_1, argv[1]);
	model_1.dim = get_mesh_dimensions(model_1.vtx, model_1.vtx_cnt);
	model_1.buffer.size = ((model_1.dim.x - 1) * (model_1.dim.z - 1)) * 2;
	model_1.buffer.tri = (t_tri *)v_alloc(sizeof(t_tri) * model_1.buffer.size);
	model_1.buffer.tri = grid_triangulation(
	model_1.buffer.tri, model_1.vtx, model_1.dim.x, model_1.vtx_cnt);
	model_1.scale = 1;
	cam_0 = create_camera((t_vct4) {45, RESX / RESY, 0.1, 1000}, 0);
	world = create_world(cam_0);
	world.buffer.size = 0;
	world.projection = PERSPECTIVE;
	add_model(&world, &model_1);
	mlx_key_hook(world.win, key_callback, &world);
	mlx_loop_hook(world.mlx, loop_callback, &world);
	mlx_loop(world.mlx);
}
