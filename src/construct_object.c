/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 03:33:43 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/11 03:29:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_object		*construct_object(char *name)
{
	t_object	*out;

	out = (t_object *)v_alloc(sizeof(t_object));
	out->name = name;
	return (out);
}
