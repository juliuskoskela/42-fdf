#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <math.h>
# include <stdio.h>
# include <stdint.h>

typedef struct	s_color
{
	uint16_t		r;
	uint16_t		g;
	uint16_t		b;
}				t_color;

typedef struct	s_vertex
{
	double			x;
	double			y;
	double			z;
	double			w;
}				t_vertex;

typedef struct	s_vector
{
	t_vertex		org;
	t_vertex		dst;
	t_vertex		vct;
}				t_vector;

t_vertex		g_vertex(double x, double y, double z);
t_vector		g_vector(t_vertex org, t_vertex dst);
t_vector		g_vct_nor(t_vector v);
t_vector		g_vct_sub(t_vector a, t_vector b);
t_vector		g_vct_add(t_vector a, t_vector b);
t_vector		g_vct_ref(t_vector v);
t_vector		g_vct_scale(t_vector v, double scalar);
t_vector		g_vct_cross(t_vector v);
double			g_vct_dot(t_vector a, t_vector b);
double			g_vct_mag(t_vector v);
#endif