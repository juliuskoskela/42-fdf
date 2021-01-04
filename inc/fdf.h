#ifndef FDF_H
# define FDF_H
# define MAX_BUFF 1000
# define RESX 2560
# define RESY 1440
# include <string.h>
# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include "../libft/inc/libft.h"
# include "../inc/mlx.h"

typedef struct		s_camera
{
	double			width;
	double			height;
	double			ratio;
	double			near;
	double			far;
	double			fov;
	t_mtx			*pos;
	t_mtx			*ori;
	t_mtx			*ovct;
	t_mtx			*tt;
	t_mtx			*tr;
	t_mtx			**xyz;
	t_mtx			*rot;
	t_mtx			*view_mtx;
	t_mtx			*proj_mtx;
	t_mtx			*comp;
}					t_camera;

typedef struct		s_object
{
	char			*file;
	double			g_scale;
	size_t			vtx_cnt;
	t_mtx			*pos;
	t_mtx			*ori;
	t_mtx			**xyz;
	t_mtx			*rot;
	t_mtx			*tt;
	t_mtx			*scl;
	t_dlist			*object_buff;
	t_mtx			*comp;
}					t_object;

typedef struct		s_world
{
	char			*name;
	int				resx;
	int				resy;
	void			*mlx_ptr;
	void			*win_ptr;
	size_t			obj_cnt;
	size_t			buffsize;
	t_camera		**cam_arr;
	t_object		**obj_arr;
	t_dlist			*wrld_prebuff;
	t_mtx			**wrld_buff;
	t_mtx			*comp;
}					t_world;

typedef struct		s_tri
{
	t_mtx			*v1;
	t_mtx			*v2;
	t_mtx			*v3;
}					t_tri;

t_world			*construct_world(int verbose);
t_camera		*construct_camera(int verbose);
t_object		*construct_object(char *file, int verbose);
void			destruct_world(t_world *wrld, int verbose);
void			destruct_camera(t_camera *cam, int verbose);
void			destruct_object(t_object *obj, int verbose);
void			set_world(t_world **wrld, int verbose);
void			set_camera(t_camera **cam, int verbose);
void			set_object(t_object **obj, int verbose);
void			process_world_buffer(t_world **wrld, int verbose);
void			comp_object(t_object **obj, int verbose);
void			comp_camera(t_camera **cam, int verbose);
void			render(t_world **wrld, t_mtx **buff, size_t buffsize);
void			printf_buff(t_dlist *buff);
t_dlist			*input_parse(char *input_file);
void			view_mtx(t_camera *cam, int verbose);
int				main(int argc, char **argv);

#endif