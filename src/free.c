/*
** EPITECH PROJECT, 2021
** free
** File description:
** malloc
*/

#include "struct.h"

static void merge_next(block_t *temp)
{
    if (temp->next->free == true) {
        temp->size += temp->next->size + sizeof(block_t);
        temp->next = temp->next->next;
        if (temp->next != NULL)
            temp->next->prev = temp;
    }
}

static void merge_prev(block_t *temp)
{
    if (temp->prev != NULL && temp->prev->free == true) {
        temp->prev->size += temp->size + sizeof(block_t);
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }
}

void free(void *ptr)
{
    block_t *temp = get_start();

    if (ptr == NULL)
        return;
    for (; temp != NULL && temp->data != ptr; temp = temp->next);
    if (temp == NULL)
        return;
    temp->free = true;
    merge_next(temp);
    merge_prev(temp);
}
