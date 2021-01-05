/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 08:36:06 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/05 02:20:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_dlist			*input_parse(char *input_file)
{
	t_parse		p;

	v_bzero(&p, sizeof(t_parse));
	p.fd = open(input_file, O_RDONLY);
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
				dl_putlast(&p.out, g_vtx(p.row, (c_atof(p.tmp) * p.sign), p.col, p.cnt));
				while (p.line[p.i] == ' ')
					p.i++;
				p.row++;
				p.cnt++;
				p.sign = 1;
			}
		}
		dl_putlast(&p.out, g_vtx(p.row, c_atof(p.tmp) * p.sign, p.col, p.cnt));
		p.sign = 1;
		p.i = 0;
		p.row = 0;
		p.col++;
		p.cnt++;
	}
	close(p.fd);
	return (p.out);
}
