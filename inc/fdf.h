#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include "../libft/inc/libft.h"
# include "../inc/mlx.h"

typedef struct		s_vtxarr
{
	t_vertex		*vtx;
	struct s_vtxarr	*next;
	struct s_vtxarr	*prev;
}					t_vtxarr;

typedef struct		s_matrix
{
	int				fov;
	t_vertex		*mx;
	t_vertex		*my;
	t_vertex		*mz;
	t_vertex		*mw;
}					t_matrix;

typedef struct		s_program
{
	char			*name;
	t_vtxarr		*map;
	int				resx;
	int				resy;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_program;

void			g_vtxarr_append(t_vtxarr **ref, t_vertex *new);
void			g_vtx_scale(t_vertex *v, double scalar);
void			g_map_scale(t_vtxarr **map, double scalar);
t_vtxarr		*input_parse(char *input_file);
void			g_drawline(t_program *p, t_vertex org, t_vertex dst);
t_program		*init(char *input_file);
t_vertex		*g_vertex(double x, double y, double z, double w);

#endif