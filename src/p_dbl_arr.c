/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_dbl_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:52:14 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:08:44 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			p_dbl_arr(double *arr, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		printf("%.1f ", arr[i]);
		i++;
	}
	printf("\n");
}
