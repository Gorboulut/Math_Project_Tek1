/*
** EPITECH PROJECT, 2019
** display_help.c
** File description:
** display_help.c
*/

#include <stdio.h>

void display_help(void)
{
    printf("USAGE\n    ./104intersection opt xp yp zp xv yv zv p\n\nDESCRIPTION\n    opt             surface option: 1 for a sphere, 2 for a cylinder, 3 for a cone\n    (xp, yp, zp)    coordinates of a point by which the light ray passes through \n    (xv, yv, zv)    coordinates of a vector parallel to the light ray\n    p               parameters: radius of the sphere, radius of the cylinder, or\n                    angle formed by the cone and the Z-axis\n");
}
