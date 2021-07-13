/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** my_malloc
*/

#include "struct.h"

void *get_start(void)
{
    static block_t *strt = NULL;

    if (strt == NULL) {
        strt = sbrk_page_size();
        if (strt == (void *) - 1)
            return (NULL);
        strt->size = get_page_size() - sizeof(block_t);
        strt->next = NULL;
        strt->prev = NULL;
        strt->free = true;
        strt->data = (void *) strt + sizeof(block_t);
    }
    return (strt);
}

static block_t *create_node(block_t *block, size_t size)
{
    block_t *new;

    while (block->size < size + sizeof(block_t)) {
        sbrk_page_size();
        block->size += get_page_size();
    }
    new = (void *)block + (sizeof(block_t) + size);
    new->size = block->size - (sizeof(block_t) + size);
    new->next = block->next;
    new->prev = block;
    new->free = true;
    block->size = size;
    block->next = new;
    block->data = (void *) block + sizeof(block_t);
    block->free = false;
    return (block);
}

static block_t *search_bestfit(block_t *block, size_t size)
{
    int pos = -1;
    size_t pos_size = 0;
    block_t *temp = block;

    for (int i = 0; temp != NULL; ++i, temp = temp->next)
        if (temp->size >= size + sizeof(block_t) && temp->free == true) {
            if (pos_size != 0 && temp->size > pos_size)
                continue;
            pos = i;
            pos_size = temp->size;
        }
    for (; pos > 0; --pos)
        block = block->next;
    if (pos == -1)
        for (; block->next != NULL; block = block->next);
    return (create_node(block, size));
}

void *malloc(size_t size)
{
    block_t *block = get_start();

    size = align_pow2(size);
    if (block == NULL)
        return (NULL);
    block = search_bestfit(block, size);
    return (block->data);
}
