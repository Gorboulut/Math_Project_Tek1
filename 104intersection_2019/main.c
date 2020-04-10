/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

void display_help(void);

int call_sphere(char **av)
{
    int xp = atoi(av[2]);
    int yp = atoi(av[3]);
    int zp = atoi(av[4]);
    int xv = atoi(av[5]);
    int yv = atoi(av[6]);
    int zv = atoi(av[7]);
    int p = atoi(av[8]);

    printf("Sphere of radius %d\n", p);
    int a = pow(xv, 2) + pow(yv, 2) + pow(zv, 2);
    int b = (2 * xp * xv) + (2 * yp * yv) + (2 * zp * zv);
    int c = pow(xp, 2) + pow(yp, 2) + pow(zp, 2) - pow(p, 2);
    int delta = b * b - 4 * a * c;
    printf("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n"
    , xp, yp, zp, xv, yv, zv);

    if (delta < 0)
        printf("No intersection point.\n");
    if (delta == 0) {
        float inter = (-b / (2 * (float)a));
        printf("1 intersection point:\n");
        printf("(%.3f, %.3f, %.3f)\n", xp + inter * xv, yp + inter * yv, zp + inter * zv);
    }
    if (delta > 0) {
        printf("2 intersection points:\n");
        float inter1 = (-b - sqrt(delta)) / (2 * a);
        float inter2 = (-b + sqrt(delta)) / (2 * a);
        printf("(%.3f, %.3f, %.3f)\n", xp + inter1 * xv, yp + inter1 * yv, zp + inter1 * zv);
        printf("(%.3f, %.3f, %.3f)\n", xp + inter2 * xv, yp + inter2 * yv, zp + inter2 * zv);
    }
    return (84);
}

int call_cyl(char **av)
{
    int xp = atoi(av[2]);
    int yp = atoi(av[3]);
    int zp = atoi(av[4]);
    int xv = atoi(av[5]);
    int yv = atoi(av[6]);
    int zv = atoi(av[7]);
    int p = atoi(av[8]);

    printf("Cylinder of radius %d\n", p);
    int a = pow(xv, 2) + pow(yv, 2);
    int b = (2 * xp * xv) + (2 * yp * yv);
    int c = pow(xp, 2) + pow(yp, 2) - pow(p, 2);
    int delta = b * b - 4 * a * c;
    printf("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n"
    , xp, yp, zp, xv, yv, zv);
    if (delta < 0)
        printf("No intersection point.\n");
    if (delta == 0) {
        float inter = -(b / (2 * (float)a));
        printf("1 intersection point:\n");
        printf("(%.3f, %.3f, %.3f)\n", xp + inter * xv, yp + inter * yv, zp + inter * zv);
    }
    if (delta > 0) {
        printf("2 intersection points:\n");
        float inter1 = (-b - sqrt(delta)) / (2 * a);
        float inter2 = (-b + sqrt(delta)) / (2 * a);
        printf("(%.3f, %.3f, %.3f)\n", xp + inter2 * xv, yp + inter2 * yv, zp + inter2 * zv);
        printf("(%.3f, %.3f, %.3f)\n", xp + inter1 * xv, yp + inter1 * yv, zp + inter1 * zv);
    }
    return (84);
}

int call_cone(char **av)
{
    int xp = atoi(av[2]);
    int yp = atoi(av[3]);
    int zp = atoi(av[4]);
    int xv = atoi(av[5]);
    int yv = atoi(av[6]);
    int zv = atoi(av[7]);
    int p = atoi(av[8]);

    printf("Cone with a %d degree angle\n", p);
    int a = pow(xv, 2) + pow(yv, 2);
    int b = (2 * xp * xv) + (2 * yp * yv);
    int c = pow(xp, 2) + pow(yp, 2) - pow(p, 2);
    int delta = b * b - 4 * a * c;
    printf("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n"
    , xp, yp, zp, xv, yv, zv);
    if (delta < 0)
        printf("No intersection point.\n");
    if (delta == 0) {
        float inter = -(b / (2 * (float)a));
        printf("1 intersection point:\n");
        printf("(%.3f, %.3f, %.3f)\n", xp + inter * xv, yp + inter * yv, zp + inter * zv);
    }
    if (delta > 0) {
        printf("2 intersection points:\n");
        float inter1 = (-b - sqrt(delta)) / (2 * a);
        float inter2 = (-b + sqrt(delta)) / (2 * a);
        printf("(%.3f, %.3f, %.3f)\n", xp + inter1 * xv, yp + inter1 * yv, zp + inter1 * zv);
        printf("(%.3f, %.3f, %.3f)\n", xp + inter2 * xv, yp + inter2 * yv, zp + inter2 * zv);
    }
    return (84);
}

int check_arg(char **av)
{
    int i = 1;

    while (av[i] != NULL) {
        if ((av[i][0] < '0' || av[i][0] > '9') && av[i][0] != '-')
            exit(84);
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h')
            display_help();
    if (ac != 9)
        return (84);
    check_arg(av);
    if (av[1][0] != '1' && av[1][0] != '2' && av[1][0] != '3')
        exit(84);
    if ((av[1][0] == '1' || av[1][0] == '2') && atof(av[8]) <= 0)
        exit(84);
    else if (av[1][0] == '3' && (atof(av[8]) < 0 || atof(av[8]) > 360))
        exit(84);
    if (av[1][0] == '1')
        call_sphere(av);
    if (av[1][0] == '2')
        call_cyl(av);
    if (av[1][0] == '3')
        call_cone(av);
    return (0);
}
