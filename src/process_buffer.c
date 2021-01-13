/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:47:50 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 18:21:01 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_tri			*process_buffer(t_tri *out, t_tri *ori, t_mtx4 mtx, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		out[i].a = g_mult_vct(mtx, ori[i].a);
		out[i].b = g_mult_vct(mtx, ori[i].b);
		out[i].c = g_mult_vct(mtx, ori[i].c);
		i++;
	}
	return (out);
}
