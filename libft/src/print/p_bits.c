/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_bits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:27:20 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/06 18:26:00 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void			p_bits(uint64_t nb, uint64_t size)
{
	uint64_t	i;
	char		c;

	i = 0;
	while (i < size)
	{
		c = b_checknth(nb, i) ? '1' : '0';
		if (!(write(1, &c, 1)))
			return ;
		i++;
	}
}

/*
**  ----------------------------------------------------------------------------
**
**	P_bits
**
**	Print `size` bits from the integer `nb`.
**
**  ----------------------------------------------------------------------------
*/