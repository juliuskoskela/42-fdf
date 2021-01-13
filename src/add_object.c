/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:02:35 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 22:54:03 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world			add_object(t_world out, t_object new, int verbose)
{
	out.objects[out.obj_cnt] = new;
	out.obj_cnt += 1;
	out.vtx_cnt += new.vtx_cnt;
	out.tri_cnt += new.tri_cnt;
	if (verbose > 0)
		printf("Object added!\n\n");
	return (out);
}
