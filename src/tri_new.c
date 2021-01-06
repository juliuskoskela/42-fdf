/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 02:34:56 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 02:35:04 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_tri			*tri_new(t_mtx *a, t_mtx *b, t_mtx *c)
{
	t_tri		*out;

	out = (t_tri *)v_alloc(sizeof(t_tri));
	out->v1 = a;
	out->v2 = b;
	out->v3 = c;
	return (out);
}
