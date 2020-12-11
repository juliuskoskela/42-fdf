/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:59:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/10 12:00:19 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "../inc/fdf.h"

// int		deal_key(int key, void *param)
// {
// 	p_char('X');
// 	return (0);
// }


// void			key_callback()
// {
// 	mlx_key_hook(p->win_ptr, deal_key, (void *)0);
// }

void			p_vertex(t_vertex v)
{
	printf("v.x: %f v.y: %f v.z: %f v.z: %f\n", v.x, v.y, v.z, v.w);
}

void			p_map(t_program *p, t_vtxarr **map)
{
	if ((*map)->next)
	{
		g_drawline(p, *(*map)->vtx, *(*map)->next->vtx);
		p_vertex(*(*map)->vtx);
		*map = (*map)->next;
		p_map(p, map);
	}
}

// Projection matrix ortho
// 100
// 010
double		vtx_mult(t_vertex a, t_vertex b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

t_vertex		*mtx_mult(t_matrix mtx, t_vertex vtx)
{
	t_vertex	*out;

	out = (t_vertex *)v_alloc(sizeof(t_vertex));
	out->x = vtx_mult(*mtx.mx, vtx);
	out->y = vtx_mult(*mtx.my, vtx);
	out->z = vtx_mult(*mtx.mz, vtx);
	out->w = vtx_mult(*mtx.mw, vtx);
	return (out);
}

t_matrix		*ortho_projection()
{
	t_matrix	*out;

	out = (t_matrix *)v_alloc(sizeof(t_matrix));
	out->mx = g_vertex(1.0, 0.0, 0.0, 1.0);
	out->my = g_vertex(0.0, 1.0, 0.0, 1.0);
	out->mz = g_vertex(0.0, 0.0, 0.0, 1.0);
	out->mw = g_vertex(0.0, 0.0, 0.0, 1.0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_program	*p;

	if (argc != 2)
		return (0);
	p = init(argv[1]);
	//g_map_scale(&p->map, 10);
	p_map(p, &p->map);
	mlx_loop(p->mlx_ptr);
	return(0);
}