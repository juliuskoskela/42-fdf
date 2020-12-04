/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vct_ref.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:14:18 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/04 21:20:26 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vector		g_vct_ref(t_vector v)
{
	t_vector	out;

	out.vct.x = v.vct.x * -1;
	out.vct.y = v.vct.y * -1;
	out.vct.z = v.vct.z * -1;
	return (out);
}
