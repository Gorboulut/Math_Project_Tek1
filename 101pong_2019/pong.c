/*
** EPITECH PROJECT, 2019
** 101pong
** File description:
** 3D vector calculator
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

int main (int argc, char **argv)
{
    double angl;
    double angl_rad;

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("%s\n", HELP_MSG);
        return (0);
    }
    if (argc != 8)
        return (84);
    if (argv[7][0] == '-')
        return (84);
    for (int i = 0; argv[7][i] != '\0'; i++)
        if (argv[7][i] == '.')
            return (84);
    float x = atof(argv[4]) - atof(argv[1]);
    float y = atof(argv[5]) - atof(argv[2]);
    float z = atof(argv[6]) - atof(argv[3]);
    int n = atoi(argv[7]);
    float ballz2 = atof(argv[6]);
    float ballz1 = atof(argv[3]);
    
    printf("%s\n", "The velocity vector of the ball is:");
    printf("%s%4.2f%s%s%4.2f%s%4.2f%s\n", "(", x, ",", " ", y, ", ", z, ")");
    printf("%s%d%s\n", "At time t + ", n, ", ball coordinates will be:");
    printf("%s%4.2f%s %4.2f%s %4.2f%s\n", "(", atof(argv[4]) + (x * n), ",", atof(argv[5]) + (y * n), ",", atof(argv[6]) + (z * n), ")");

    if (z != 0 && x != 0 &&(-ballz2/(ballz2-ballz1) > 0)) {
        angl_rad = acos(z/(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))));
        angl = 180*(angl_rad - (M_PI/2))/M_PI;
        angl = fabs(angl);
        printf("The incidence angle is:\n%.2f degrees\n", angl);
    }
    else
        printf("The ball won't reach the paddle.\n");
    return (0);
}
