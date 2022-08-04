# FDF

A 42-school project to create a CPU 3D rasterizer. Includes both perspective and
orthographic projections of the input.

## Usage

```
make
./fdf [map_file]
```

## Description

A program that takes in a matrix representation of points with heights

```
0 0 1 2 3 4 5 6 7 8 9
0 0 0 1 2 3 4 5 6 7 8
0 0 0 0 1 2 3 4 5 6 7
0 0 0 0 0 1 2 3 4 5 6
0 0 0 0 0 0 1 2 3 4 5
0 0 0 0 0 0 0 1 2 3 4
0 0 0 0 0 0 0 0 1 2 3
0 0 0 0 0 0 0 0 0 1 2
0 0 0 0 0 0 0 0 0 0 1
```

...and turns it into a 3D representation

W, A, S, D, Up, Down, Left and Right keys turn the camera.

1 and 2 switch between perspective and orthographic view.