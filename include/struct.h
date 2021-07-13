/*
** EPITECH PROJECT, 2021
** struct
** File description:
** malloc
*/

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TESTS
#define malloc my_malloc
#define free my_free
#define realloc my_realloc
#define reallocarray my_reallocarray
#define calloc my_calloc
#endif

typedef struct block_s
{
    size_t size;
    struct block_s *next;
    struct block_s *prev;
    bool free;
    void *data;
} block_t;

int get_page_size(void);
void *get_start(void);
void *sbrk_page_size(void);
void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
size_t align_pow2(size_t size);
