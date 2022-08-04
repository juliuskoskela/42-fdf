/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_model.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 02:39:58 by jkoskela          #+#    #+#             */
/*   Updated: 2021/03/03 06:38:28 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_mtx4			g_model(t_vct4 rot, t_vct4 pos, double scale)
{
	t_mtx4		model;
	t_mtx4		rotation;
	t_mtx4		translation;
	t_mtx4		transformation;

	rotation = g_rotation(rot.x, rot.y, rot.z);
	translation = g_translate(pos);
	transformation = g_scale(scale);
	model = g_mult_mtx(translation, g_mult_mtx(rotation, transformation));
	return (model);
}

/*
**	---------------------------------------------------------------------------
**
**	G_MODEL
**
**	Returns a matrix that transaltes a model space vertex into world space.
**
**	MODEL = ROTATION(obj.rot) * TRANSLATION(obj.pos) * TRANSFORMATION(obj.scale)
**
**	v_w = MODEL * v_o
*/
