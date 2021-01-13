/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:57:00 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/12 21:19:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_tri			*allocate_buffer(size_t size)
{
	t_tri		*out;

	if (!(out = (t_tri *)v_alloc(sizeof(t_tri) * size)))
		error("Malloc failure in allocating buffer.\n");
	return (out);
}
