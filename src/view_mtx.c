/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_mtx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 02:17:34 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/06 23:53:03 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		print_method(t_camera *cam)
{
	printf("# Camera pipeline\n\n");

	printf("#### Camera position vertex\n\n");
	printf("This vertex denotes the camera objects position in 3d-space.\n\n");
	printf("\\( pos_x = %.2fpx \\) \n", cam->pos->this[0]);
	printf("\\( pos_y = %.2fpx \\) \n", cam->pos->this[1]);
	printf("\\( pos_z = %.2fpx \\) \n\n", cam->pos->this[2]);

	printf("#### Camera orientation vector\n\n");
	printf("This is the orientation vector for the cameras view frustum.\n\n");
	printf("\\( ori_x = %.1f\\degree \\) \n", cam->ori->this[0]);
	printf("\\( ori_y = %.1f\\degree \\) \n", cam->ori->this[1]);
	printf("\\( ori_z = %.1f\\degree \\) \n\n", cam->ori->this[2]);

	printf("## Rotation matrices\n\n");
	printf("In order to orient the cameras view frustum we create a rotation matrix from the orientation in degrees of each axis.\n\n");
	printf("\\( X = (x_5 = cos(ori_x)) + (x_6 = -sin(ori_x)) + (x_9 = sin(ori_x)) + (x_10 = cos(ori_x)) \\)\n\n");
	mtx_print(cam->xyz[0]);
	printf("\n \\( Y = (x_0 = cos(ori_y)) + (x_2 = sin(ori_y)) + (x_9 = sin(ori_y)) + (x_10 = cos(ori_y)) \\)\n\n");
	mtx_print(cam->xyz[1]);
	printf("\n \\( Z = (x_0 = cos(ori_z)) + (x_1 = -sin(ori_z)) + (x_4 = sin(ori_z)) + (x_5 = cos(ori_z)) \\)\n\n");
	mtx_print(cam->xyz[2]);
	printf("\nFor the final rotation matrix we combine the rotation around each axis to matrix `R` by multiplying the rotation matrices `X`, `Y` and `Z` in decending order.\n\n");
	printf("\n \\( R = X \\cdot Y \\cdot Z \\) \n\n");
	mtx_print(cam->rot);

	printf("\n## g_trans matrices\n\n");
	printf("#### Opposite position vector\n\n");
	printf("In order to get a g_trans matrix for the orientation we first get the opposite vector `ovtc` of the vector `ori`.\n\n");
	printf("\\( ovct_x = %.2fpx \\) \n", cam->ovct->this[0]);
	printf("\\( ovct_y = %.2fpx \\) \n", cam->ovct->this[1]);
	printf("\\( ovct_z = %.2fpx \\) \n\n", cam->ovct->this[2]);
	printf("We create a g_trans matrix `tT` from `ovtc`.\n\n");
	printf("\n \\( tT = (tt_3 = ovct_0) + (tt_7 = ovct_1) + (tt_11 = ovct_2) \\) \n\n");
	mtx_print(cam->tt);
	printf("\nWe transpose the rotation matrix `R` to get `tR`.\n\n");
	printf("\n \\( tR = R^T \\) \n\n");
	mtx_print(cam->tr);

	printf("\n## View matrix\n\n");
	printf("We create the view matrix by multiplying `tR` and `tT`.\n\n");
	printf("\n \\( V = tR \\cdot tT \\) \n\n");
	mtx_print(cam->view_mtx);
	printf("\n");
}

void			view_mtx(t_camera *cam, int verbose)
{
	g_rotx(cam->xyz[0], cam->ori->this[0]);
	g_roty(cam->xyz[1], cam->ori->this[1]);
	g_rotz(cam->xyz[2], cam->ori->this[2]);
	mtx_multiply(cam->rot, cam->xyz[0], cam->xyz[1]);
	mtx_multiply(cam->rot, cam->rot, cam->xyz[2]);
	mtx_transpose(cam->tr, cam->rot);
	cam->ovct->this = vct_opp(cam->pos->this, 3);
	g_trans(cam->tt, cam->ovct);
	mtx_multiply(cam->view_mtx, cam->tr, cam->tt);
	if (verbose > 0)
		print_method(cam);
}

/*
**  ----------------------------------------------------------------------------
**
**	View_mtx
**
**	1. Rotation matrix `R` from camera origin.
**	2. Origin matrix `tR` is created by transposing the rotation matrix `R`.
**	3. Calculate the opposite vector of the given camera position.
**	4. G_trans matrix `tT` from ovct.
**	5. Multiply `tR * tT` to get `view_mtx`.
**
*/
