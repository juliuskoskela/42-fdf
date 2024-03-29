/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:33:18 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 03:42:11 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void destroy_buffer(t_buffer *buffer)
{
	free(buffer->tri);
	buffer->size = 0;
	buffer = NULL;
	if (g_verbose > 0)
		printf("SUCCESS: Buffer destroyed!\n");
}
