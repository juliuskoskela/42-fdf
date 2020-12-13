X |  mx  |  my  |  mz  |  mw  |
--|------|------|------|------|
x |  1.0 |  0.0 |  0.0 |  0.0 |
y |  0.0 |  0.9 | -0.3 |  0.0 |
z |  0.0 |  0.3 |  0.9 |  0.0 |
w |  0.0 |  0.0 |  0.0 |  1.0 |

Y |  mx  |  my  |  mz  |  mw  |
--|------|------|------|------|
x |  0.9 |  0.0 | -0.3 |  0.0 |
y |  0.0 |  1.0 |  0.0 |  0.0 |
z |  0.3 |  0.0 |  0.9 |  0.0 |
w |  0.0 |  0.0 |  0.0 |  1.0 |

Z |  mx  |  my  |  mz  |  mw  |
--|------|------|------|------|
x |  0.9 |  0.3 |  0.0 |  0.0 |
y |  0.0 |  1.0 |  0.0 |  0.0 |
z | -0.3 |  0.9 |  1.0 |  0.0 |
w |  0.0 |  0.0 |  0.0 |  1.0 |

T |  mx  |  my  |  mz  |  mw  |
--|------|------|------|------|
x |  1.0 |  0.0 |  0.0 | 10.0 |
y |  0.0 |  1.0 |  0.0 |  5.0 |
z |  0.0 |  0.0 |  1.0 |  7.0 |
w |  0.0 |  0.0 |  0.0 |  1.0 |

P |  mx  |  my  |  mz  |  mw  |
--|------|------|------|------|
x |  1.7 |  0.0 |  0.0 |  0.0 |
y |  0.0 |  1.7 |  0.0 |  0.0 |
z |  0.0 |  0.0 | -2.0 |  0.0 |
w |  0.0 |  0.0 | -1.0 |  0.0 |

M  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 | 1.00 | 0.00 | 0.00 | 0.00
r1 | 0.00 | 0.71 | -0.71 | 0.00
r2 | 0.00 | 0.71 | 0.71 | 0.00
r3 | 0.00 | 0.00 | 0.00 | 1.00

M  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 | 1.00 | 0.00 | 0.00 | 0.00
r1 | 0.00 | -0.00 | -1.00 | 0.00
r2 | 0.00 | 1.00 | -0.00 | 0.00
r3 | 0.00 | 0.00 | 0.00 | 1.00

M  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 | 1.00 | 0.00 | 0.00 | 0.00
r1 | 0.00 | 1.00 | -0.00 | 0.00
r2 | 0.00 | 0.00 | 1.00 | 0.00
r3 | 0.00 | 0.00 | 0.00 | 1.00

M  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 | 1.30 | 0.00 | 0.00 | 0.00
r1 | 0.00 | 1.73 | 0.00 | 0.00
r2 | 0.00 | 0.00 | -0.96 | -1.96
r3 | 0.00 | 0.00 | -1.00 | 0.00

M  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 | 1.00 | 0.00 | 0.00 | 1.00
r1 | 0.00 | 1.00 | 0.00 | 1.00
r2 | 0.00 | 0.00 | 1.00 | 0.00
r3 | 0.00 | 0.00 | 0.00 | 1.00

M  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 | 10.00 | 0.00 | 0.00 | 0.00
r1 | 0.00 | 10.00 | 0.00 | 0.00
r2 | 0.00 | 0.00 | 10.00 | 0.00
r3 | 0.00 | 0.00 | 0.00 | 1.00

M  |  c0   |  c1   |  c2   |  c3
---|-------|-------|-------|-------
r0 | 10.00 | 0.00 | 0.00 | 10.00
r1 | 0.00 | -7.07 | -7.07 | -7.07
r2 | 0.00 | 7.07 | -7.07 | 7.07
r3 | 0.00 | 0.00 | 0.00 | 1.00

Let's start with an harmless identity matrix :
Matrix IDENTITY instance constructed
|-----|------|------|-----|
|1.00 | 0.00 | 0.00 | 0.00|
|0.00 | 1.00 | 0.00 | 0.00|
|0.00 | 0.00 | 1.00 | 0.00|
|0.00 | 0.00 | 0.00 | 1.00|

So far, so good. Let's create a translation matrix now.
Matrix TRANSLATION preset instance constructed
T | vtcX | vtcY | vtcZ | vtxO
-----------------------------
x | 1.00 | 0.00 | 0.00 | 20.00
y | 0.00 | 1.00 | 0.00 | 20.00
z | 0.00 | 0.00 | 1.00 | 0.00
w | 0.00 | 0.00 | 0.00 | 1.00

A scale matrix is no big deal.
Matrix SCALE preset instance constructed
S | vtcX | vtcY | vtcZ | vtxO
-----------------------------
x | 10.00 | 0.00 | 0.00 | 0.00
y | 0.00 | 10.00 | 0.00 | 0.00
z | 0.00 | 0.00 | 10.00 | 0.00
w | 0.00 | 0.00 | 0.00 | 1.00

A Rotation along the OX axis :
Matrix Ox ROTATION preset instance constructed
X | vtcX | vtcY | vtcZ | vtxO
-----------------------------
x | 1.00 | 0.00 | 0.00 | 0.00
y | 0.00 | 0.71 | -0.71 | 0.00
z | 0.00 | 0.71 | 0.71 | 0.00
w | 0.00 | 0.00 | 0.00 | 1.00

Or along the OY axis :
Matrix Oy ROTATION preset instance constructed
Y | vtcX | vtcY | vtcZ | vtxO
-----------------------------
x | 0.00 | 0.00 | 1.00 | 0.00
y | 0.00 | 1.00 | 0.00 | 0.00
z | -1.00 | 0.00 | 0.00 | 0.00
w | 0.00 | 0.00 | 0.00 | 1.00

Do a barrel roll !
Matrix Oz ROTATION preset instance constructed
Z | vtcX | vtcY | vtcZ | vtxO
-----------------------------
x | 1.00 | 0.00 | 0.00 | 0.00
y | -0.00 | 1.00 | 0.00 | 0.00
z | 0.00 | 0.00 | 1.00 | 0.00
w | 0.00 | 0.00 | 0.00 | 1.00

The bad guy now, the projection matrix : 3D to 2D !
The values are arbitray. We'll decipher them in the next exercice.
Matrix PROJECTION preset instance constructed
P | vtcX | vtcY | vtcZ | vtxO
-----------------------------
x | 1.30 | 0.00 | 0.00 | 0.00
y | 0.00 | 1.73 | 0.00 | 0.00
z | 0.00 | 0.00 | -0.96 | -1.96
w | 0.00 | 0.00 | -1.00 | 0.00

Matrices are so awesome, that they can be combined !
This is a model matrix that scales, then rotates around OY axis,
then rotates around OX axis and finally translates.
Please note the reverse operations order. It's not an error.
Matrix instance destructed
Matrix instance destructed
M | vtcX | vtcY | vtcZ | vtxO
-----------------------------
x | 0.00 | 0.00 | 10.00 | 20.00
y | 7.07 | 7.07 | -0.00 | 20.00
z | -7.07 | 7.07 | 0.00 | 0.00
w | 0.00 | 0.00 | 0.00 | 1.00

What can you do with a matrix and a vertex ?
Vertex( x: 1.00, y: 1.00, z:0.00, w:1.00 )
M | vtcX | vtcY | vtcZ | vtxO
-----------------------------
x | 0.00 | 0.00 | 10.00 | 20.00
y | 7.07 | 7.07 | -0.00 | 20.00
z | -7.07 | 7.07 | 0.00 | 0.00
w | 0.00 | 0.00 | 0.00 | 1.00
Transform the damn vertex !
Vertex( x: 20.00, y: 34.14, z:-0.00, w:1.00 )

Matrix instance destructed
Matrix instance destructed
Matrix instance destructed
Matrix instance destructed
Matrix instance destructed
Matrix instance destructed
Matrix instance destructed
Matrix instance destructed

double		tmp1[9] = { 5, 2, 3,
							1, 7, 3,
							5, 2, 4, };