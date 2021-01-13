/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:47:50 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/12 21:21:07 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_tri			*process_buffer(t_tri *buff, t_tri *ori, t_mtx4 comp, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		buff[i].a = g_mult_vct(comp, ori[i].a);
		buff[i].b = g_mult_vct(comp, ori[i].b);
		buff[i].c = g_mult_vct(comp, ori[i].c);
		i++;
	}
	return (buff);
}
