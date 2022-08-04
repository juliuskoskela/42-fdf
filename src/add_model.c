/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_model.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:02:35 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 03:42:11 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void add_model(t_world *wld, t_model *new)
{
	wld->buffer.size += new->buffer.size;
	if (wld->obj_cnt == MAX_MODELS)
	{
		printf("ERROR: Maximum object count reached, can't add object!\n");
		return ;
	}
	wld->models[wld->obj_cnt] = *new;
	wld->obj_cnt += 1;
	if (g_verbose > 0)
		printf("SUCCESS: Object added to world!\n");
}
