/*
** EPITECH PROJECT, 2021
** utils
** File description:
** malloc
*/

#include "struct.h"

size_t align_pow2(size_t size)
{
    size_t pow = 1;

    while (pow < size)
        pow *= 2;
    return (pow == 1 ? 2 : pow);
}

int get_page_size(void)
{
    static int page_size = -1;

    page_size = page_size == -1 ? getpagesize() * 24 : page_size;
    return (page_size);
}

void *sbrk_page_size(void)
{
    return (sbrk(get_page_size()));
}
