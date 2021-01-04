/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_world_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 04:14:26 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/04 04:45:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			process_world_buffer(t_world **wrld, int verbose)
{
	size_t		i;
	t_mtx		*tmp;
	t_dlist		*pos;

	i = 0;
	tmp = NULL;
	pos = (*wrld)->wrld_prebuff;
	while (pos)
	{
		(*wrld)->wrld_buff[i] = mtx_new(c_itoa(i), 1, 2);
		tmp = pos->content;
		mtx_multiply((*wrld)->wrld_buff[i], (*wrld)->comp, tmp);
		pos = pos->next;
		i++;
	}
	if (verbose == 1)
		printf("World buffer processed!\n\n");
}
