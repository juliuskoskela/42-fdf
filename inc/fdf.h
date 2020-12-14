#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include "../libft/inc/libft.h"
# include "../inc/mlx.h"

typedef struct	s_mtx
{
	size_t		x;
	size_t		y;
	double		*this;
	char		*name;
}				t_mtx;

typedef struct		s_program
{
	char			*name;
	t_dlist			*map;
	double			resx;
	double			resy;
	double			ratio;
	double			near;
	double			far;
	double			scale;
	double			fov;
	double			angle_x;
	double			angle_y;
	double			angle_z;
	size_t			map_rows;
	size_t			map_cols;
	t_mtx			*transformation_matrix;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_program;

double			m_dot(double *a, double *b, size_t size);
double			m_rad(double dgr);
double			m_dgr(double rad);
double			*vtx_new(double x, double y, double z, double w);
t_mtx			*mtx_cpy(double arr[], size_t rows, size_t cols);
double			*mtx_get_col(t_mtx *mtx, size_t col);
double			*mtx_get_row(t_mtx *mtx, size_t row);
t_mtx			*mtx_multiply(t_mtx *a, t_mtx *b);
t_mtx			*mtx_new(char *name, size_t rows, size_t cols);
void			mtx_print(t_mtx	*mtx);
double			*mtx_vtx(t_mtx *mtx, double vtx[]);
void			p_dbl_arr(double *arr, size_t size);
t_mtx			*identity(size_t scale);
t_mtx			*translation(double vtx[]);
t_mtx			*projection(double ratio, double near, double far, double fov);
t_mtx			*rot_x(double angle);
t_mtx			*rot_y(double angle);
t_mtx			*rot_z(double angle);
int				mtx_tests(void);
int				main(int argc, char **argv);
t_dlist			*input_parse(t_program *fdf, char *input_file);
void			p_map(t_dlist **map);
t_mtx			*mtx_transpose(t_mtx *in);


#endif