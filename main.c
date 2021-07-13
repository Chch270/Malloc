/*
** EPITECH PROJECT, 2021
** main
** File description:
** main test
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <stdbool.h>

void *malloc(size_t size);
void free(void *ptr);

void my_putstr(char *str)
{
    write(1, str, strlen(str));
}

int main(void)
{
    char *str = NULL;

    for (int i = 0; i != 20000; ++i)
        str = malloc(1000);

//    str = strcpy(str, "Hello\n");
//    write(1, str, strlen(str));
//    str = realloc(str, 11);
//    my_putstr(str);
//    str = strcpy(str, "HelloAAAAA\n");
//    my_putstr(str);
}
