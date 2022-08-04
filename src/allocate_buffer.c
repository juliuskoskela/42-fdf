/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:57:00 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 03:42:11 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_buffer allocate_buffer(size_t size)
{
	t_buffer	new;

	new.size = size;
	if (!(new.tri = (t_tri *)v_alloc(sizeof(t_tri) * size)))
		error("FATAL ERROR: Malloc failed in create_buffer!\n");
	if (g_verbose > 0)
		printf("SUCCESS: Buffer of size %zu created!\n", new.size);
	return (new);
}
