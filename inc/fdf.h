/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 06:07:20 by jkoskela          #+#    #+#             */
/*   Updated: 2022/08/04 03:40:30 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX_BUFFER 1000000
# define MAX_MODELS 5
# define RESX 1280
# define RESY 720
# include <string.h>
# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include "../libft/inc/libft.h"
# include "../inc/mlx.h"
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_E 101
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52
# define KEY_C 99
# define KEY_R 114
# define KEY_F 102
# define KEY_G 103
# define KEY_H 104
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define WHITE 0XFFFFFF
# define PERSPECTIVE 0X1
# define ORTHOGRAPHIC 0X2
# define SCREEN_OFFSET_X 0
# define SCREEN_OFFSET_Y 0

typedef struct		s_buffer
{
	size_t			size;
	t_tri			*tri;
}					t_buffer;

typedef struct		s_camera
{
	size_t			id;
	double			fov;
	double			ratio;
	double			near;
	double			far;
	t_vct4			pos;
	t_vct4			rot;
}					t_camera;

typedef struct		s_model
{
	size_t			id;
	double			scale;
	t_vct4			pos;
	t_vct4			rot;
	t_vct4			dim;
	t_vct4			*vtx;
	size_t			vtx_cnt;
	t_buffer		buffer;
}					t_model;

typedef struct		s_world
{
	size_t			projection;
	void			*mlx;
	void			*win;
	t_model			*models;
	size_t			obj_cnt;
	t_camera		a_cam;
	t_buffer		buffer;
}					t_world;

int					g_verbose;

t_buffer			allocate_buffer(size_t size);
void				add_model(t_world *wld, t_model *new_model);
void				print_buffer(t_buffer buffer);
size_t				process_buffer(t_buffer *v, t_mtx4 m);
void				destroy_buffer(t_buffer *buffer);
int					key_callback(int keycode, t_world *w);
int					loop_callback(t_world *world);

t_camera			create_camera(t_vct4 vrs, size_t id);
t_model				create_model(size_t id);
t_world				create_world(t_camera cam);

size_t				world_from_model(t_world *wld);
size_t				view_from_world(t_world *wld);
size_t				clip_from_view(t_world *wld);
size_t				window_from_clip(t_world *wld);

void				parse_file(t_model *mod, char *file);
void				draw_line(void *mlx, void *win, t_vct4 v0, t_vct4 v1);
t_tri				*grid_triangulation(t_tri *d, t_vct4 *s,
					size_t w, size_t size);
t_vct4				get_mesh_dimensions(t_vct4 *shape, size_t size);

int					main(int argc, char **argv);

#endif
