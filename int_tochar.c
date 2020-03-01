/*
** EPITECH PROJECT, 2019
** int_tochar
** File description:
** int_tochar
*/
#include <stdlib.h>

char *nb_tochar(int i)
{
    int length = 0;
    int negative = 0;
    if (i == 0)
        length++;
    for (int k = i; k != 0; k = k/10, length++);
    if (i < 0) {
        length++;
        negative = 1;
        i = i * (-1);
    }
    char *c = malloc(sizeof(char) * (length + 1));
    c[length] = '\0';
    length--;
    for (; length >= 0; length--) {
        c[length] = i % 10 + 48;
        i = i / 10;
    }
    if (negative)
        c[0] = '-';
    return (c);
}
