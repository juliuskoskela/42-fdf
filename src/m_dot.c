/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_dot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:50:19 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:06:03 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double			m_dot(double *a, double *b, size_t size)
{
	double		out;
	size_t		i;

	i = 0;
	out = 0.0;
	while (i < size)
	{
		out = out + a[i] * b[i];
		i++;
	}
	return (out);
}
