/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:58:30 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/11 17:20:28 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		print_buff(t_tri *buff, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		g_print_vct(buff[i].a, i);
		g_print_vct(buff[i].b, i);
		g_print_vct(buff[i].c, i);
		printf("\n");
		i++;
	}
	p_char('\n');
}
