/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_mtx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 02:48:47 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/15 02:48:49 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx			*object_mtx(t_mtx *rot, t_mtx *scale, t_mtx *move)
{
	return (mtx_multiply(rot, mtx_multiply(scale, move)));
}
