/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tri_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:58:30 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/12 21:03:36 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			print_tri_arr(t_tri *arr, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		g_print_vct(arr[i].a, i);
		g_print_vct(arr[i].b, i);
		g_print_vct(arr[i].c, i);
		printf("\n");
		i++;
	}
	p_char('\n');
}
