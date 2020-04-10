/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** achitect projet
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int call_t_func(char **av)
{
    printf("Translation along vector (%s, %s)\n", av[4], av[5]);
    printf("1.00    0.00    %.2f\n0.00    1.00    %.2f\n0.00    0.00    1.00\n", atof(av[4]), atof(av[5]));
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", atof(av[1]), atof(av[2]), atof(av[1]) + atof(av[4]), atof(av[2]) + atof(av[5]));
    return (0);
}

int call_z_func(char **av)
{
    printf("Scalling by factors %s and %s\n", av[4], av[5]);
    printf("%.2f    0.00    0.00\n0.00    %.2f    0.00\n0.00    0.00    1.00\n", atof(av[4]), atof(av[5]), atof(av[5]));
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", atof(av[1]), atof(av[2]), atof(av[1]) * atof(av[4]), atof(av[2]) * atof(av[5]));
    return (0);
}

int check_error(char **av)
{
    int i = 1;

    while (av[i] != NULL) {
        if ((av[i][0] < '0' || av[i][0] > '9') && av[i][0] != '-')
            exit(84);
        if (av[i][1] == 't' && (av[i + 3] != NULL || av[i + 2] == NULL
                                || av[i + 1] == NULL))
            exit(84);
        if (av[i][1] == 'z' && (av[i + 3] != NULL || av[i + 2] == NULL
                                || av[i + 1] == NULL))
            exit(84);
        if (av[i][1] == 'r' && (av[i + 2] != NULL || av[i + 1] == NULL))
            exit(84);
        if (av[i][1] == 's' && (av[i + 2] != NULL || av[i + 1] == NULL))
            exit(84);
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        printf("USAGE\n   ./102 architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...\n\nDESCRIPTION\n    x    abscissa of the original point\n    y   ordinate of the original point\n\n    transfo arg1 [arg2]\n    -t i j translation along vector (i, j)\n    -z m n scaling by factors m (x-axis) and n (y-axis)\n    -r d   rotation centered in O by a d degree angle\n    -s d   reflection over the axis passing through O with an inclination angle of d degrees\n");
        return (0);
    }
    if (ac < 5)
        return (84);
    check_error(av);
    if (av[3][1] == 't')
        call_t_func(av);
    if(av[3][1] == 'z')
        call_z_func(av);
    if (av[3][1] == 'r')
        printf("Rotation by a %s degree angle\n", av[4]);
    if(av[3][1] == 's')
        printf("Reflection over an axis with an inclination angle of %s degrees\n", av[4]);
    return (0);
}
