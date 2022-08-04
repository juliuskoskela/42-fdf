/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:16:33 by jkoskela          #+#    #+#             */
/*   Updated: 2021/03/06 00:22:44 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			print_buffer(t_buffer buffer)
{
	size_t		i;

	i = 0;
	while (i < buffer.size)
	{
		g_print_vct(buffer.tri[i].a, i);
		g_print_vct(buffer.tri[i].b, i);
		g_print_vct(buffer.tri[i].c, i);
		i++;
	}
}
