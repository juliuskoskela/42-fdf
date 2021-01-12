/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 20:16:30 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/12 18:42:29 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mtx4			look_at(t_vct4 from, t_vct4 to, int verbose)
{
	t_vct4		forward;
	t_vct4		right;
	t_vct4		up;
	t_vct4		tmp;
	t_mtx4		out;

	tmp = g_sub(from, to);
	forward = g_norm(tmp);
	tmp = g_vct4(0, 1, 0, 0);
	tmp = g_norm(tmp);
	right = g_cross(tmp, forward);
	up = g_cross(forward, right);
	out.name = ("L");
	out.v1 = right;
	out.v2 = up;
	out.v3 = forward;
	out.v4 = from;
	out.v4.w = 1;
	if (verbose < 0)
		g_print_mtx(out);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	Step 1: compute the forward axis.
**
**	The forward axis of the camera local coordinate system is aligned along
**	the line segment defined by the points from and to. Normalize the vector
**	To−From (mind the direction of this vector: it is To−From not From−To).
**
**	Vec3f forward = Normalize(from - to);
**
**  ----------------------------------------------------------------------------
**
**	Step 2: compute the right vector.
**
**	Cartesian coordinates are defined by three unit vectors that are
**	perpendicular to each other. f we take two vectors A and B they can be seen
**	as lying into a plane, and that the cross product of these two vectors
**	create a third vector C perpendicular to that plane and thus also obviously
**	perpendicular to A and B. We can use this property to create our right
**	vector. This idea here is to use some arbitrary vector and compute the
**	cross vector between the forward vector and this "arbitrary" vector. The
**	result is a vector that is necessarily perpendicular to the forward vector
**	and that can be used in the construction of our Cartesian coordinate system
**	as the right vector. The code for computing this vector is simple since it
**	only implies a cross product between the forward vector and this arbitrary
**	vector:
**
**	Vec3f right = crossProduct(randomVec, forward);
**
**	the vector (0,1,0) can clearly be used in place of what we called earlier
**	our arbitrary vector.
**
**	Vec3f tmp(0, 1, 0);
**	Vec3f right = crossProduct(Normalize(tmp), forward);
**
**  ----------------------------------------------------------------------------
**
**	Step 3: compute the up vector.
**
**	We have two orthogonal vectors, the forward and right vector, so computing
**	the cross product between this two vectors will give us the missing third
**	vector, the up vector. Note that if the forward and right vector are
**	normalized, then the resulting up vector computed from the cross product
**	will be normalized too:
**
**	Vec3f up = crossProduct(forward, right);
**
**  ----------------------------------------------------------------------------
**
**	Step 4: set the 4x4 matrix using the right, up and forward vector as from
**	point.
**
**	Row 1: replace the first three coefficients of the row with the coordinates
**	of the right vector.
**	Row 2: replace the first three coefficients of the row with the coordinates
**	of the up vector.
**	Row 3: replace the first three coefficients of the row with the coordinates
**	of the forward vector.
**	Row 4: replace the first three coefficients of the row with the coordinates
**	of the from point.
**
**	L  |  c0   |  c1   |  c2   |  c3
**	---|-------|-------|-------|-------
**	r0 |  r.x  |  r.y  |  r.z  |  0.00
**	r1 |  u.x  |  u.y  |  u.z  |  0.00
**	r2 |  fw.x |  fw.x |  fw.x |  0.00
**	r3 |  fr.x |  fr.x |  fr.x |  1.00
**
*/