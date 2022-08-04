/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_model.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:00:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/03/08 16:32:23 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_model		create_model(size_t id)
{
	t_model	obj;

	obj.id = id;
	obj.scale = 1;
	obj.pos = (t_vct4) {0.0, 0.0, 0.0, 1.0};
	obj.rot = (t_vct4) {0.0, 0.0, 0.0, 1.0};
	if (g_verbose > 0)
		printf("SUCCESS: Object created!\n");
	return (obj);
}
