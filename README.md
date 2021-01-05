# Camera pipeline

#### Camera position vertex

This vertex denotes the camera objects position in 3d-space.

\( pos_x = 10.00px \)
\( pos_y = 10.00px \)
\( pos_z = 20.00px \)

#### Camera orientation vector

This is the orientation vector for the cameras view frustum.

\( ori_x = 1.0\degree \)
\( ori_y = 1.0\degree \)
\( ori_z = 1.0\degree \)

## Rotation matrices

In order to orient the cameras view frustum we create a rotation matrix from the orientation in degrees of each axis.

\( X = (x_5 = cos(ori_x)) + (x_6 = -sin(ori_x)) + (x_9 = sin(ori_x)) + (x_10 = cos(ori_x)) \)

X  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 |  1.00 | -0.02 |  0.00 |  0.00
r1 |  0.02 |  1.00 |  0.00 |  0.00
r2 |  0.00 |  0.00 |  1.00 |  0.00
r3 |  0.00 |  0.00 |  0.00 |  1.00


 \( Y = (x_0 = cos(ori_y)) + (x_2 = sin(ori_y)) + (x_9 = sin(ori_y)) + (x_10 = cos(ori_y)) \)

Y  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 |  1.00 |  0.00 |  0.02 |  0.00
r1 |  0.00 |  1.00 |  0.00 |  0.00
r2 | -0.02 |  0.00 |  1.00 |  0.00
r3 |  0.00 |  0.00 |  0.00 |  1.00


 \( Z = (x_0 = cos(ori_z)) + (x_1 = -sin(ori_z)) + (x_4 = sin(ori_z)) + (x_5 = cos(ori_z)) \)

Z  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 |  1.00 |  0.00 |  0.00 |  0.00
r1 |  0.00 |  1.00 | -0.02 |  0.00
r2 |  0.00 |  0.02 |  1.00 |  0.00
r3 |  0.00 |  0.00 |  0.00 |  1.00


For the final rotation matrix we combine the rotation around each axis to matrix `R` by multiplying the rotation matrices `X`, `Y` and `Z` in decending order.


 \( R = X \cdot Y \cdot Z \)

R  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 |  1.00 | -0.02 |  0.02 |  0.00
r1 |  0.02 |  1.00 |  0.00 |  0.00
r2 | -0.02 |  0.00 |  1.00 |  0.00
r3 |  0.00 |  0.00 |  0.00 |  1.00


## g_trans matrices

#### Opposite position vector

In order to get a g_trans matrix for the orientation we first get the opposite vector `ovtc` of the vector `ori`.

\( ovct_x = -10.00px \)
\( ovct_y = -10.00px \)
\( ovct_z = -20.00px \)

We create a g_trans matrix `tT` from `ovtc`.


 \( tT = (tt_3 = ovct_0) + (tt_7 = ovct_1) + (tt_11 = ovct_2) \)

tT  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 |  1.00 |  0.00 |  0.00 | -10.00
r1 |  0.00 |  1.00 |  0.00 | -10.00
r2 |  0.00 |  0.00 |  1.00 | -20.00
r3 |  0.00 |  0.00 |  0.00 |  1.00


We transpose the rotation matrix `R` to get `tR`.


 \( tR = R^T \)

tR  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 |  1.00 |  0.02 | -0.02 |  0.00
r1 | -0.02 |  1.00 |  0.00 |  0.00
r2 |  0.02 |  0.00 |  1.00 |  0.00
r3 |  0.00 |  0.00 |  0.00 |  1.00


## View matrix

We create the view matrix by multiplying `tR` and `tT`.


 \( V = tR \cdot tT \)

V  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 |  1.00 |  0.02 | -0.02 | -9.82
r1 | -0.02 |  1.00 |  0.00 | -9.83
r2 |  0.02 |  0.00 |  1.00 | -20.17
r3 |  0.00 |  0.00 |  0.00 |  1.00