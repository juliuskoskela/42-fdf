/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:45:41 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:06:32 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx			*mtx_cpy(double arr[], size_t rows, size_t cols)
{
	size_t		i;
	t_mtx		*out;

	i = 0;
	out = (t_mtx *)v_alloc(sizeof(t_mtx));
	out->this = (double *)v_alloc(sizeof(double) * (rows * cols));
	out->x = rows;
	out->y = cols;
	while (i < rows * cols)
	{
		out->this[i] = arr[i];
		i++;
	}
	return (out);
}
