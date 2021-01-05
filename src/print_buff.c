/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:58:30 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/04 20:55:07 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			print_buff(t_dlist *buff)
{
	t_dlist		*tmp;
	t_mtx		*cast;

	tmp = buff;
	while (tmp)
	{
		cast = tmp->content;
		mtx_print(cast);
		tmp = tmp->next;
	}
}
