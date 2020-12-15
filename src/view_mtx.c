/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_mtx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 02:48:01 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/15 04:27:20 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx			*view_mtx(double *pos, double *rot)
{
	t_mtx		*out;

	out = rotation(rot);
	out = mtx_multiply(out, mtx_transpose(translation(vct_opposite(pos))));
	return (out);
}
