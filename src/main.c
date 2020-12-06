/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:59:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/12/06 08:50:20 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../libft/inc/libft.h"

typedef struct		s_program
{
	char	*name;
	int		resx;
	int		resy;
	void	*mlx_ptr;
	void	*win_ptr;
}					t_program;


int		deal_key(int key, void *param)
{
	p_char('X');
	return (0);
}

t_program		*init()
{
	t_program	out;

	out.name = s_dup("fdf");
	out.resx = 1280;
	out.resy = 720;
	out.mlx_ptr = mlx_init();
	out.win_ptr = mlx_new_window(out.mlx_ptr, out.resx, out.resy, "fdf");
}

void			line_draw(t_vertex org, t_vertex dst)
{

}
int			main()
{
	t_program	p;

	p = init();
	mlx_pixel_put(p.mlx_ptr, p.win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(p.win_ptr, deal_key, (void *)0);
	mlx_loop(p.mlx_ptr);
	return(0);
}