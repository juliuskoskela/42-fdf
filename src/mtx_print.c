/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:47:51 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:08:12 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			mtx_print(t_mtx	*mtx)
{
	size_t		i;
	size_t		j;
	size_t		r;

	i = 0;
	j = 0;
	r = 0;
	printf("%s  ", mtx->name);
	while (i < mtx->x)
	{
		printf("|  c%zu   ", i);
		i++;
	}
	i = 0;
	printf("\n---");
	while (i < mtx->x)
	{
		printf("|-------");
		i++;
	}
	i = 0;
	printf("\n");
	printf("r%zu ", r);
	while (i < mtx->x * mtx->y)
	{
		if (j == mtx->x)
		{
			printf("\n");
			r++;
			printf("r%zu ", r);
			j = 0;
		}
		printf("| %5.2f ", mtx->this[i]);
		i++;
		j++;
	}
	printf("\n");
}
