/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vct_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:56:35 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/12 20:56:36 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			print_vct_arr(t_vct4 *arr, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		g_print_vct(arr[i], i);
		i++;
	}
}
