/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:46:45 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:07:55 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx			*mtx_new(char *name, size_t rows, size_t cols)
{
	size_t		i;
	t_mtx		*out;

	i = 0;
	out = (t_mtx *)v_alloc(sizeof(t_mtx));
	out->name = s_dup(name);
	out->this = (double *)v_alloc(sizeof(double) * (rows * cols));
	out->x = rows;
	out->y = cols;
	while (i < rows * cols)
	{
		out->this[i] = 0.0;
		i++;
	}
	return (out);
}
