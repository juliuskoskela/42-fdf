/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 08:36:06 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/06 11:55:51 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_dlist			*input_parse(char *input_file)
{
	int			fd;
	int			row;
	int			col;
	int			i;
	int			j;
	int			sign;
	char		tmp[10];
	char		*line;
	t_dlist		*out;
	t_vertex	*vtx;

	fd = open(input_file, O_RDONLY);
	col = 0;
	row = 0;
	i = 0;
	j = 0;
	sign = 0;
	out = NULL;
	while (fd_readline(fd, &line) > 0)
	{
		while (line[i])
		{
			if (line[i] == '-')
				sign = -1;
			else if (is_digit(line[i]))
			{
				tmp[j] = line[i];
				j++;
			}
			else if (line[i] == ' ')
			{
				vtx = g_vertex(row, c_atoi(tmp), col, 1.0);
				dl_putlast(&out, vtx);
				row++;
				j = 0;
			}
		}
	}
	close(fd);
	return (out);
}
