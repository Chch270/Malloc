/*
** EPITECH PROJECT, 2021
** realloc array
** File description:
** malloc
*/

#include "struct.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t res;

    if (__builtin_mul_overflow(nmemb, size, &res))
        return (NULL);
    return (realloc(ptr, res));
}
