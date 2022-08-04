/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_dup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:28:35 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/15 01:38:15 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char			*s_dup(const char *s1)
{
	char		*out;
	uint64_t	i;

	i = 0;
	out = (char *)v_alloc(sizeof(char) * s_len(s1) + 1);
	if (out == NULL)
		return (NULL);
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_cdup
**
**	String duplicate (c); duplicate contents from string `s1`.
**
**	Returns a memory allocated output `out`.
**
**  ----------------------------------------------------------------------------
*/
