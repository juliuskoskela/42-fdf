#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include "../libft/inc/libft.h"
# include "../inc/mlx.h"

typedef struct		s_mtx
{
	size_t			x;
	size_t			y;
	double			*this;
	char			*name;
}					t_mtx;

typedef struct		s_object
{
	double			*pos;
	double			*rot;
	double			scalar;
	t_mtx			*xyz;
	t_mtx			*mov;
	t_mtx			*scl;
	t_mtx			*cmp;
	t_mtx			*(*object_cmp)(t_mtx *, t_mtx *, t_mtx *);
	t_mtx			*(*rotate)(double *);
	t_mtx			*(*move)(double *);
	t_mtx			*(*scale)(size_t);
	void			(*transform)(t_dlist *, t_mtx *);
	t_dlist			*object_buffer;
}					t_object;

typedef struct		s_camera
{
	double			*pos;
	double			*rot;
	double			ratio;
	double			near;
	double			far;
	double			fov;
	t_mtx			*proj;
	t_mtx			*view;
	t_mtx			*cmp;
	t_mtx			*(*view_mtx)(double *, double *);
	t_mtx			*(*projection)(double, double, double, double);
}					t_camera;

typedef struct		s_world
{
	double			resx;
	double			resy;
	size_t			obj_cnt;
	t_object		**world_buffer;
	t_camera		*camera;
	void			(*transform)(t_dlist *, t_mtx *);
}					t_world;

typedef struct		s_program
{
	char			*name;
	t_world			*world;
}					t_program;

double			m_dot(double *a, double *b, size_t size);
double			m_rad(double dgr);
double			m_dgr(double rad);
double			*vtx_new(double x, double y, double z, double w, double c);
t_mtx			*mtx_cpy(double arr[], size_t rows, size_t cols);
double			*mtx_get_col(t_mtx *mtx, size_t col);
double			*mtx_get_row(t_mtx *mtx, size_t row);
t_mtx			*mtx_multiply(t_mtx *a, t_mtx *b);
t_mtx			*mtx_new(char *name, size_t rows, size_t cols);
void			mtx_print(t_mtx	*mtx);
double			*mtx_vtx(t_mtx *mtx, double vtx[]);
void			p_dbl_arr(double *arr, size_t size);
t_mtx			*identity(size_t scale);
t_mtx			*translation(double *vtx);
t_mtx			*projection(double ratio, double near, double far, double fov);
t_mtx			*rot_x(double angle);
t_mtx			*rot_y(double angle);
t_mtx			*rot_z(double angle);
int				mtx_tests(void);
int				main(int argc, char **argv);
t_dlist			*input_parse(char *input_file);
void			p_map(t_dlist **map);
t_mtx			*mtx_transpose(t_mtx *in);
t_mtx			*rotation(double *rot);
double			vct_magnitude(double *vct);
double			*vct_opposite(double *vct);
t_mtx			*view_mtx(double *pos, double *rot);
t_mtx			*object_mtx(t_mtx *rot, t_mtx *scale, t_mtx *move);
void			transform(t_dlist *verteces, t_mtx *object_mtx);
t_camera		*construct_camera();
t_world			*construct_world();
t_object		*construct_object(t_dlist *object_buffer);
t_program		*construct_program();
int				key_callback(int keycode, t_program *p);


#endif