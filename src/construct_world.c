/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 02:52:01 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/15 05:40:06 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world			*construct_world()
{
	t_world		*out;

	out = (t_world *)v_alloc(sizeof(t_world));
	out->obj_cnt = 0.0;
	out->resy = 0.0;
	out->resy = 0.0;
	out->camera = NULL;
	out->world_buffer = NULL;
	out->transform = &transform;
	return (out);
}
