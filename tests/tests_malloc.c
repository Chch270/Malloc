/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** units tests malloc
*/

#include <criterion/criterion.h>
#include <../include/struct.h>

void *my_malloc(size_t size);
void *my_calloc(size_t nmemb, size_t size);
void *my_reallocarray(void *ptr, size_t nmemb, size_t size);

Test(tests_malloc, test_malloc_basic)
{
    char *str = my_malloc(sizeof(char) * 10);

    str = strcpy(str, "hello!");
    cr_assert_str_eq(str, "hello!");
}

Test(tests_malloc, test_malloc_multiple)
{
    char **str = my_malloc(sizeof(char *) * 1000);

    for (int i = 0; i != 10; ++i) {
        str[i] = my_malloc(sizeof(char) * 10000);
        str[i] = strcpy(str[i], "hello!");
    }
    cr_assert_str_eq(str[1], "hello!");
}

Test(tests_malloc, best_fit)
{
    char *str = my_malloc(sizeof(char) * 100);
    void *ptr = str;
    char *str2 = malloc(10000);
    
    free(str);
    str = my_malloc(sizeof(char) * 10);
    cr_assert(str == ptr);
}

Test(tests_free, test_free_ptr)
{
    char *str = my_malloc(sizeof(char) * 100);

    my_free(str);
}

Test(tests_free, test_multiple_free)
{
    char *str1 = my_malloc(sizeof(char) * 100);
    char *str2 = my_malloc(sizeof(char) * 100);
    char *str3 = my_malloc(sizeof(char) * 100);

    my_free(str1);
    my_free(str3);
    my_free(str2);
}

Test(tests_free, test_multiple_error_gestion)
{
    char *str = "coucou";

    my_free(NULL);
    my_free(str);
}

Test(tests_free, test_search_mini_free)
{
    char **str = malloc(1000 * sizeof(char *));
    char *str2;
    void *ptr;

    for (int i = 0; i != 1000; ++i) {
        str[i] = malloc(10000 - i);
    }
    ptr = str[100];
    my_free(str[100]);
    my_free(str[66]);
    my_free(str[33]);
    str2 = malloc(10);
    cr_assert(str2 == ptr);
}


Test(tests_realloc, test_realloc_basic)
{
    char *str = malloc(1);

    str = realloc(str, 10);
    str = strcpy(str, "coucou");
    cr_assert_str_eq(str, "coucou");
}

Test(tests_realloc, test_realloc_null)
{
    char *str = my_realloc(NULL, 10);

    str = strcpy(str, "coucou");
    cr_assert_str_eq(str, "coucou");
}

Test(tests_realloc, test_realloc_error_gestion)
{
    char *str = "hello";

    str = my_realloc(str, 10);
    cr_assert(str == NULL);
}

Test(tests_realloc, test_realloc_size_upper)
{
    char *str = my_malloc(1000);
    void *ptr = str;

    str = my_realloc(str, 10);
    cr_assert(ptr == str);
}

Test(tests_calloc, test_calloc_basic)
{
    char *str = my_calloc(1, 10);

    str = strcpy(str, "coucou");
    cr_assert_str_eq(str, "coucou");
}

Test(tests_realloc, test_realloc_array_basic)
{
    char *str = malloc(10);

    str = my_reallocarray(str, sizeof(char), 100);
    str = strcpy(str, "coucou");
    cr_assert_str_eq(str, "coucou");
}
