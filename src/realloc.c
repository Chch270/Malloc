/*
** EPITECH PROJECT, 2021
** realloc
** File description:
** malloc
*/

#include "struct.h"

void *realloc(void *ptr, size_t size)
{
    void *new;
    block_t *temp = get_start();

    size = align_pow2(size);
    if (ptr == NULL)
        return ((new = malloc(size)) == NULL ? NULL : new);
    for (; temp != NULL && temp->data != ptr; temp = temp->next);
    if (temp == NULL)
        return (NULL);
    if (temp->size >= size)
        return (ptr);
    if ((new = malloc(size)) == NULL)
        return (NULL);
    new = memcpy(new, ptr, temp->size);
    free(ptr);
    return (new);
}
