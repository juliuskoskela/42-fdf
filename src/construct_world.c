/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 14:48:51 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/11 03:30:14 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world			*construct_world(char *name)
{
	t_world		*out;

	out = (t_world *)v_alloc(sizeof(t_world));
	out->name = name;
	return (out);
}
