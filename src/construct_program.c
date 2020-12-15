/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_program.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 02:53:38 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/15 05:22:01 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_program			*construct_program()
{
	t_program		*out;
/*
**	Initialize program:
*/
	out = (t_program *)v_alloc(sizeof(t_program));
	out->name = s_dup("fdf");
/*
**	Initialize world:
*/
	out->world = construct_world();
/*
**	Initialize camera:
*/
	out->world->camera = construct_camera();
	return (out);
}
