/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:59:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/06 21:11:47 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "../inc/fdf.h"

typedef struct		s_program
{
	char	*name;
	t_dlist	*map;
	int		resx;
	int		resy;
	void	*mlx_ptr;
	void	*win_ptr;
}					t_program;


// int		deal_key(int key, void *param)
// {
// 	p_char('X');
// 	return (0);
// }

t_program		*init(char *input_file)
{
	t_program	*out;

	out = (t_program *)v_alloc(sizeof(t_program));
	out->name = s_dup("fdf");
	out->map = input_parse(input_file);
	out->resx = 1280;
	out->resy = 720;
	out->mlx_ptr = mlx_init();
	out->win_ptr = mlx_new_window(out->mlx_ptr, out->resx, out->resy, "fdf");
	return (out);
}

// void			key_callback()
// {
// 	mlx_key_hook(p->win_ptr, deal_key, (void *)0);
// }

void			p_vertex(t_vertex v)
{
	printf("v.x: %f v.y: %f v.z: %f v.z: %f\n", v.x, v.y, v.z, v.w);
}

void			p_map(t_dlist **map)
{
	t_vertex	*tmp;

	if ((*map)->next)
	{
		tmp = (*map)->content;
		p_vertex(*tmp);
		*map = (*map)->next;
		p_map(map);
	}
}

void			line_draw(t_program *p, t_vertex org, t_vertex dst)
{
	t_vertex	tmp;

	tmp = org;
	while (tmp.x <= dst.x && tmp.y <= dst.y)
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, (int)tmp.x, (int)tmp.y, 0xFFFFFF);
		tmp.x = tmp.x + 1.0;
		tmp.y = tmp.y + 1.0;
	}
}

int			main(int argc, char **argv)
{
	t_program	*p;
	// t_vertex	*org = g_vertex(0, 0, 0, 1.0);
	// t_vertex	*dst = g_vertex(200, 300, 0, 1.0);

	if (argc != 2)
		return (0);
	p = init(argv[1]);
	p_map(&p->map);
	// line_draw(p, *org, *dst);
	// mlx_loop(p->mlx_ptr);
	return(0);
}