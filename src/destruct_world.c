/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:52:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/02 01:19:52 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fdf.h"

void			destruct_world(t_world *wrld, int verbose)
{
	mtx_free(wrld->comp);
	free(wrld);
	if (verbose == 1)
		printf("\nWorld destructed!\n\n");
}
