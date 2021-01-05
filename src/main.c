/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 03:43:04 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/05 07:06:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// static t_mtx		**list_to_arr(t_dlist *list, size_t size)
// {
// 	t_mtx		**out;
// 	t_dlist		*tmp;
// 	size_t		i;

// 	i = 0;
// 	tmp = list;
// 	out = (t_mtx **)v_alloc(sizeof(t_mtx *) * size);
// 	while (tmp)
// 	{
// 		out[i] = tmp->content;
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	return (out);
// }

void			print_buffer(t_mtx **buff, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		mtx_print(buff[i]);
		i++;
	}
}

t_dlist			*dl_join(t_dlist *head, t_dlist *tail)
{
	t_dlist		*out;

	out = head;
	while (head->next)
		head = head->next;
	head->next = tail;
	return (out);
}

int				main(int argc, char **argv)
{
	t_world		*wrld;
	t_camera	*cam1;
	t_object	*obj1;
	int			verbose;

	argc = 0;
	verbose = 1;

	wrld = construct_world(verbose);
	cam1 = construct_camera(verbose);
	obj1 = construct_object(s_dup(argv[1]), verbose);

	set_world(&wrld, verbose);
	set_camera(&cam1, verbose);
	set_object(&obj1, verbose);

	comp_camera(&cam1, verbose);
	comp_object(&obj1, verbose);

	proc_buff(obj1->obj_buff, obj1->comp, verbose);
	wrld->wrld_buff = obj1->obj_buff;
	proc_buff(wrld->wrld_buff, cam1->comp, verbose);
	print_buff(wrld->wrld_buff);
	render(&wrld);
	mlx_loop(wrld->mlx_ptr);
	return (0);
}

