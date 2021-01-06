/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 08:36:06 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 17:24:47 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_dlist			*input_parse(t_object *obj)
{
	t_parse		p;
	int			y;

	v_bzero(&p, sizeof(t_parse));
	p.fd = open(obj->file, O_RDONLY);
	p.sign = 1;
	p.tmp = (char *)v_alloc(sizeof(char) * 10);
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
				dl_putlast(&p.out, g_vtx(obj->x, y, obj->z, obj->vtx_cnt));
				while (p.line[p.i] == ' ')
					p.i++;
				obj->x++;
				obj->vtx_cnt++;
				p.sign = 1;
			}
		}
		y = c_atof(p.tmp) * p.sign;
		dl_putlast(&p.out, g_vtx(obj->x, y, obj->z, obj->vtx_cnt));
		p.sign = 1;
		p.i = 0;
		obj->x = 0;
		obj->z++;
		obj->vtx_cnt++;
	}
	obj->x = obj->vtx_cnt / obj->z;
	close(p.fd);
	return (p.out);
}
