/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 06:07:20 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/13 02:45:41 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX_BUFF 1000000
# define RESX 1920
# define RESY 1280
# include <string.h>
# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include "../libft/inc/libft.h"
# include "../inc/mlx.h"

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
	t_mtx4			view_mtx;
	t_mtx4			proj_mtx;
}					t_camera;

typedef struct		s_object
{
	char			*name;
	double			scale;
	t_vct4			dimensions;
	t_vct4			position;
	t_vct4			direction;
	t_mtx4			rotx;
	t_mtx4			roty;
	t_mtx4			rotz;
	t_mtx4			rotation;
	t_mtx4			translation;
	t_mtx4			transformation;
	t_mtx4			model_mtx;
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
	t_mtx4			world_mtx;
	size_t			obj_cnt;
	size_t			cam_cnt;
	size_t			vtx_cnt;
	size_t			tri_cnt;
	t_camera		active_camera;
	t_camera		*cameras;
	t_object		*objects;
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

void			draw_line(void *mlx, void *win, t_vct4 v0, t_vct4 v1);
t_object		create_mesh(char *file, char *name, int verbose);
t_camera		create_camera(char *name, int verbose);
t_world			create_world(char *name, int verbose);
t_world			activate_camera(t_world out, size_t i, int verbose);
t_world			add_camera(t_world out, t_camera new, int verbose);
t_world			add_object(t_world out, t_object new, int verbose);
t_world			process_world(t_world out, int verbose);
int				key_callback(int keycode, t_world *wrld);
t_tri			*allocate_buffer(size_t size);
void			print_vct_arr(t_vct4 *arr, size_t size);
t_tri			*grid_triangulation(t_tri *d, t_vct4 *s, size_t w, size_t size);
t_tri			*process_buffer(t_tri *buff, t_tri *ori, t_mtx4 comp, size_t size);
t_vct4			get_mesh_dimensions(t_vct4 *shape, size_t size);
t_mtx4			compose_model(t_object obj, int verbose);
t_mtx4			compose_view(t_camera cam, int verbose);
t_object		shape_cube(t_object obj);
t_object		shape_tetra(t_object obj);
t_object		shape_file(t_object obj, char *file);
t_mtx4			look_at(t_vct4 from, t_vct4 to, int vebrose);
void			render(t_world wrld);
void			print_tri_arr(t_tri *arr, size_t size);
int				main(int argc, char **argv);

#endif
