/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vtx_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:24:50 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:04:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void		g_vtx_scale(t_vertex *v, double scalar)
{
	v->x = v->x * scalar;
	v->y = v->y * scalar;
	v->z = v->z * scalar;
}