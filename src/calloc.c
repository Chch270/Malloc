/*
** EPITECH PROJECT, 2021
** calloc
** File description:
** malloc
*/

#include "struct.h"

void *calloc(size_t nmemb, size_t size)
{
    void *new = malloc((nmemb + 1) * size);

    if (new == NULL)
        return (NULL);
    new = memset(new, 0, (nmemb + 1) * size);
    return (new);
}
