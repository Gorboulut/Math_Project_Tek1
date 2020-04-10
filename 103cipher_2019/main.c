/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** math project
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int message_matrix(int *matrix, char **av)
{
    int *msg_matrix = malloc(sizeof(int*) * my_strlen(av[1]));
    int *result = malloc(sizeof(int*) * my_strlen(av[1]));
    int x = 0;
    int y = 0;
    int z = 1;
    int a = 0;
    int len = my_strlen(av[1]);

    if (my_strlen(av[2]) <= 4) {
        while (z < len) {
            printf("%d %d", av[1][a] * matrix[0] + av[1][z] * matrix[2], av[1][a] * matrix[1] + av[1][z] * matrix[3]);
            a += 2;
            z += 2;
            if (z < len)
                printf(" ");
        }
        printf("\n");
        return (0);
    }
    if (my_strlen(av[2]) <= 9) {
        for (int i = 0; i < my_strlen(av[1]); i++)
            msg_matrix[i] = av[1][i];
        for (int i = 0; i < my_strlen(av[1]) + 2; i++) {
            result[i] = msg_matrix[y] * matrix[x] + msg_matrix[y + 1] * matrix[x + 3] + msg_matrix[y + 2] * matrix[x + 6];
            x++;
            if (x == 3) {
                x = 0;
                y = y + 3;
            }
        }
        free(matrix);
        free(msg_matrix);
        printf("\nEncrypted message:\n");
        for (int i = 0; i < my_strlen(av[1]) + 2 && result[i] != 0; i++) {
            if (i == 0)
                printf("%d", result[i]);
            else
                printf(" %d", result[i]);
        }
        printf("\n");
        free(result);
        return (0);
    }
    return (0);
}

int decryption(char **av, int ac)
{
    int *matrix = malloc(sizeof(int*) * 20);
    int z = 0;

    for (int i = 0; i < 20; i++)
        matrix[i] = '\0';
    for (int i = 0; i < 20; i++)
        if (av[2][i] == '0')
            av[2][i] = '\0';
    printf("Key matrix:\n");
    matrix[0] = av[2][0];
    matrix[1] = av[2][1];
    matrix[2] = av[2][2];
    matrix[3] = av[2][3];
    matrix[4] = av[2][4];
    matrix[5] = av[2][5];
    matrix[6] = av[2][6];
    matrix[7] = av[2][7];
    matrix[8] = av[2][8];
    int pri = my_strlen(av[2]);
    if (pri <= 1) {
        for (int i = 0; i < 1; i++)
          if (matrix[i] != 0)
            printf("%d\t", matrix[i]);
        printf("\n");
    }
    else if (pri <= 4) {
      for (int i = 0; i < 2; i++) {
        for (int x = 0; x < 2; x++) {
          if (matrix[z] != 0)
            printf("%d\t", matrix[z]);
          z++;
        }
        printf("\n");
      }
    }
    else if (pri <= 6) {
        for (int x = 0; x < 2; x++) {
          for (int i = 0; i < 3; i++) {
            if (matrix[z] != 0)
              printf("%d\t",  matrix[z]);
            z++;
            }
            printf("\n");
        }
    }
    else if (pri <= 9) {
        for (int x = 0; x < 3; x++) {
          for (int i = 0; i < 3; i++) {
            if (matrix[z] != 0)
              printf("%d\t", matrix[z]);
            z++;
            }
            printf("\n");
        }
    }
    else if (pri <= 14) {
      matrix[9] = av[2][9];
      matrix[10] = av[2][10];
      matrix[11] = av[2][11];
      matrix[12] = av[2][12];
      matrix[13] = av[2][13];
        for (int x = 0; x < 4; x++) {
          for (int i = 0; i < 4; i++) {
            if (matrix[z] != 0)
              printf("%d\t", matrix[z]);
            z++;
          }
          printf("\n");
        }
    }
    message_matrix(matrix, av);
    return (0);
}

int encryption(char **av)
{

}

void print_help(void)
{
    printf("USAGE\n    ./103cipher message key flag\n\nDESCRIPTION\n    message     a message, made of ASCII characters\n    key         the encryption key, made of ASCII characters\n    flag        0 for the message to be encrypted, 1 to be decrypted\n");
}

int errorcheck(int ac, char **av)
{
    int a = my_strlen(av[2]);

    if (av[3][0] != '1' && av[3][0] != '0')
        exit(84);
    if (a > '9' && a < '1')
        exit(84);
}
int main(int ac, char **av)
{
    if (ac < 2 || ac > 4 || ac == 3)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_help();
        return (0);
    }
    errorcheck(ac, av);
    if (av[3][0] == '0')
        decryption(av, ac);
    if (av[3][0] == '1')
        encryption(av);
    return (0);
}
