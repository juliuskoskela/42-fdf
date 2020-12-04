/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_vct_ref.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:14:18 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/04 13:28:48 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vector		g_vct_ref(t_vector v)
{
	t_vector	out;
	out.org.x = v.org.x * -1;
	out.org.y = v.org.y * -1;
	out.org.z = v.org.z * -1;
	out.dst.x = v.dst.x * -1;
	out.dst.y = v.dst.y * -1;
	out.dst.z = v.dst.z * -1;
	out.vct.x = v.vct.x * -1;
	out.vct.y = v.vct.y * -1;
	out.vct.z = v.vct.z * -1;
	return (out);
}
