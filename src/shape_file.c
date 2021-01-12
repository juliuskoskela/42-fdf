/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 08:36:06 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/12 17:51:00 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_object			shape_file(t_object obj, char *file)
{
	t_parse		p;
	int			y;
	int			i;
	int			j;

	v_bzero(&p, sizeof(t_parse));
	p.fd = open(file, O_RDONLY);
	p.sign = 1;
	p.tmp = (char *)v_alloc(sizeof(char) * 10);
	obj.shape = (t_vct4 *)v_alloc(sizeof(t_vct4) * MAX_BUFF);
	i = 0;
	j = 0;
	obj.vtx_cnt = 0;
	while (fd_readline(p.fd, &p.line) > 0)
	{
		while (p.line[p.i])
		{
			if (p.line[p.i] == '-')
			{
				p.sign = -1;
				p.i++;
			}
			else if (is_digit(p.line[p.i]))
			{
				while (is_digit(p.line[p.i]))
					p.tmp[p.j++] = p.line[p.i++];
				p.j = 0;
			}
			else if (p.line[p.i] == ' ')
			{
				y = c_atof(p.tmp) * p.sign;
				obj.shape[obj.vtx_cnt] = g_vct4(i, y, j, 1);
				while (p.line[p.i] == ' ')
					p.i++;
				i++;
				obj.vtx_cnt++;
				p.sign = 1;
			}
		}
		y = c_atof(p.tmp) * p.sign;
		obj.shape[obj.vtx_cnt] = g_vct4(i, y, j, 1);
		p.sign = 1;
		p.i = 0;
		i = 0;
		j++;
		obj.vtx_cnt++;
	}
	close(p.fd);
	return (obj);
}
