/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:17:58 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/12 04:17:59 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_matrix		*mtx_id(double scl)
{
	t_matrix	*out;

	out = (t_matrix *)v_alloc(sizeof(t_matrix));
	out->mx = g_vertex(scl, 0.0, 0.0, 0.0);
	out->my = g_vertex(0.0, scl, 0.0, 0.0);
	out->mz = g_vertex(0.0, 0.0, scl, 0.0);
	out->mw = g_vertex(0.0, 0.0, 0.0, 1.0);
	return (out);
}
