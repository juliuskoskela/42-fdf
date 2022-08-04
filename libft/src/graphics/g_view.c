/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_view.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 02:43:07 by jkoskela          #+#    #+#             */
/*   Updated: 2021/03/03 06:38:28 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_mtx4			g_view(t_vct4 rot, t_vct4 pos)
{
	t_mtx4		view;
	t_mtx4		rotation;
	t_mtx4		translation;

	rotation = g_transpose(g_rotation(rot.x, rot.y, rot.z));
	translation = g_translate(g_opp(pos));
	view = g_mult_mtx(translation, rotation);
	return (view);
}

/*
**	---------------------------------------------------------------------------
**
**	G_VIEW
**
**	Returns a matrix that translates a world space vertex into view space.
**
**	TR = transpose(ROTATION(cam.rot))
**	TT = TRANSLATION(opposite(cam.pos))
**	VIEW = TR * TT
**
**	v_e = VIEW * v_w
*/
