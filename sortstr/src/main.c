/*

    PROJECT: SORT ARRAY OF STRINGS
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string_array(char **array, int count);
int compare_strings(const void *a, const void *b);

int main(void)
{
    char *fruits[] = {"strawberry", "apple", "mango", "cherry", "banana", "pineapple"};
    int count;

    count = sizeof(fruits) / sizeof(fruits[0]);

    printf("SORT STRINGS\n");
    printf("Program by Farhan Ali Qureshi\n\n");

    printf("Before sorting: ");
    print_string_array(fruits, count);
    printf("\n\n");

    qsort(fruits, count, sizeof(char*), compare_strings);

    printf("After sorting: ");
    print_string_array(fruits, count);
    printf("\n\n");

    printf("End of program.\n");
    return 0;
}

void print_string_array(char **array, int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        printf("%s", array[i]);
        if (i < count - 1) printf(", ");
    }
}

int compare_strings(const void *v1, const void *v2)
{
    const char **p1;
    const char **p2;

    p1 = (const char **)v1;
    p2 = (const char **)v2;

    return strcmp(*p1, *p2);
}