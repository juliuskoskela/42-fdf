/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 08:34:18 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/13 18:04:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

t_program		*init(char *input_file)
{
	t_program	*out;

	out = (t_program *)v_alloc(sizeof(t_program));
	out->name = s_dup("fdf");
	out->map = input_parse(input_file);
	out->resx = 1280;
	out->resy = 720;
	out->mlx_ptr = mlx_init();
	out->win_ptr = mlx_new_window(out->mlx_ptr, out->resx, out->resy, "fdf");
	return (out);
}