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

void			proc_buff(t_dlist *buff, t_mtx *comp, int verbose)
{
	t_mtx		*cast;
	t_mtx		*mult;

	mult = mtx_new("tmp", 1, 4);
	while (buff)
	{
		if ((cast = buff->content) != NULL)
		{
			mtx_multiply(mult, comp, cast);
			mtx_cpy(cast, mult);
		}
		buff = buff->next;
	}
	free(mult);
	if (verbose > 0)
		printf("Buffer processed!\n\n");
}
