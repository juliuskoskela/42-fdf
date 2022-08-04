/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:03:52 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/19 23:53:59 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void		dl_print_s(t_dlist *node)
{
	char	*tmp;

	while (node)
	{
		tmp = node->content;
		p_str(tmp);
		node = node->next;
	}
}

/*
**  ----------------------------------------------------------------------------
**
**	Dl_print
**
**	Print list.
**
**  ----------------------------------------------------------------------------
*/