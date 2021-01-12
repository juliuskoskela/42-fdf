/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 06:07:20 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/11 19:02:42 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX_BUFF 10000
# define RESX 1920
# define RESY 1280
# include <string.h>
# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include "../libft/inc/libft.h"
# include "../inc/mlx.h"

// typedef struct		s_camera
// {
// 	double			ratio;
// 	double			near;
// 	double			far;
// 	double			fov;
// 	double			*watch;
// 	t_mtx			*pos;
// 	t_mtx			*ori;
// 	t_mtx			*ovct;
// 	t_mtx			*tt;
// 	t_mtx			*tr;
// 	t_mtx			**xyz;
// 	t_mtx			*rot;
// 	t_mtx			*view_mtx;
// 	t_mtx			*g_proj;
// 	t_mtx			*comp;
// }					t_camera;

// typedef struct		s_object
// {
// 	char			*file;
// 	double			g_scale;
// 	size_t			vtx_cnt;
// 	size_t			x;
// 	size_t			y;
// 	size_t			z;
// 	t_mtx			*pos;
// 	t_mtx			*ori;
// 	t_mtx			**xyz;
// 	t_mtx			*rot;
// 	t_mtx			*tt;
// 	t_mtx			*scl;
// 	t_mtx			*comp;
// 	t_dlist			*obj_vtx_buff;
// 	t_dlist			*obj_tri_buff;
// 	t_mtx			**zbuff;
// 	t_vct4			buffer[MAX_BUFF];
// }					t_object;

// typedef struct		s_world
// {
// 	char			*name;
// 	void			*mlx_ptr;
// 	void			*win_ptr;
// 	size_t			obj_cnt;
// 	size_t			buffsize;
// 	t_camera		**cam_arr;
// 	t_object		**obj_arr;
// 	t_dlist			*wrld_vtx_buff;
// 	t_dlist			*wrld_tri_buff;
// 	t_mtx			**zbuff;
// 	size_t			size;
// 	t_mtx			*comp;
// }					t_world;

typedef struct		s_camera
{
	char			*name;
	double			ratio;
	double			near;
	double			far;
	double			fov;
	t_vct4			position;
	t_vct4			direction;
	t_vct4			ovct;
	t_mtx4			tt;
	t_mtx4			tr;
	t_mtx4			rotx;
	t_mtx4			roty;
	t_mtx4			rotz;
	t_mtx4			rotation;
	t_mtx4			view;
	t_mtx4			projection;
}					t_camera;

typedef struct		s_object
{
	char			*name;
	double			scale;
	double			width;
	double			height;
	double			depth;
	t_vct4			position;
	t_vct4			direction;
	t_mtx4			rotx;
	t_mtx4			roty;
	t_mtx4			rotz;
	t_mtx4			rotation;
	t_mtx4			translation;
	t_mtx4			transformation;
	t_mtx4			comp;
	size_t			vtx_cnt;
	size_t			tri_cnt;
	t_vct4			*shape;
	t_tri			*buffer;
}					t_object;

typedef struct		s_world
{
	char			*name;
	void			*mlx_ptr;
	void			*win_ptr;
	t_mtx4			projection;
	t_mtx4			comp;
	size_t			obj_cnt;
	size_t			cam_cnt;
	size_t			vtx_cnt;
	t_camera		*cam_arr;
	t_object		*obj_arr;
	t_tri			*buffer;
}					t_world;

typedef struct		s_parse
{
	int				fd;
	int				i;
	int				j;
	int				sign;
	char			*tmp;
	char			*line;
	t_dlist			*out;
}					t_parse;

t_mtx4			comp_model(t_object obj, int verbose);
t_mtx4			comp_view(t_camera cam, int verbose);
t_vct4			*shape_cube();
t_vct4			*shape_tetra();
t_object		shape_file(t_object obj, char *file);
t_mtx4			look_at(t_vct4 from, t_vct4 to, int vebrose);
void			render(t_tri *buff, void *mlx_ptr, void *win_ptr, size_t size);
void			print_buff(t_tri *buff, size_t size);
int				main(int argc, char **argv);

#endif
