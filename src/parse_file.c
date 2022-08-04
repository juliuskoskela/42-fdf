/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 08:36:06 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 03:42:55 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static t_vct4 parse_line(t_model *mod, char *line, t_vct4 i)
{
	char	tmp[100];

	while (line[(size_t)i.w])
	{
		if (is_numeric(line[(size_t)i.w]))
		{
			while (is_numeric(line[(size_t)i.w]))
				tmp[(size_t)i.y++] = line[(size_t)i.w++];
			tmp[(size_t)i.y] = '\0';
			i.y = 0;
		}
		else if (line[(size_t)i.w] == ' ')
		{
			mod->vtx[mod->vtx_cnt++] = (t_vct4) {i.x, c_atoi(tmp), i.z, 1};
			while (line[(size_t)i.w] == ' ')
				i.w++;
			i.x += 1.0;
		}
	}
	mod->vtx[mod->vtx_cnt++] = (t_vct4) {i.x, c_atoi(tmp), i.z, 1};
	free(line);
	return ((t_vct4) {0.0, i.y, i.z += 1.0, 0.0});
}

static int parse(t_model *mod, int fd, char *line, t_vct4 i)
{
	int	ret;

	while ((ret = fd_readline(fd, &line)) > 0)
		i = parse_line(mod, line, i);
	return (ret);
}

void parse_file(t_model *mod, char *file)
{
	int	fd;

	mod->vtx_cnt = 0;
	mod->vtx = (t_vct4 *)v_alloc(sizeof(t_vct4) * MAX_BUFFER);
	if ((fd = open(file, O_RDONLY)) < 0)
		error("Can't open file!\n");
	if ((parse(mod, fd, NULL, (t_vct4) {0, 0, 0, 0})) < 0)
		error("Can't read file!\n");
	close(fd);
}
