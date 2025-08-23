/*

    PROJECT: SORT ARRAY OF INTEGERS
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_NUMBERS 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100

void print_number_array(int *array, int count);
int compare_numbers(const void *a, const void *b);

int main(void)
{
    int numbers[TOTAL_NUMBERS], i;

    srand(time(NULL));
    for (i = 0; i < TOTAL_NUMBERS; i++)
        numbers[i] = (rand() % MAX_NUMBER) + MIN_NUMBER;

    printf("SORT NUMBERS\n");
    printf("Program by Farhan Ali Qureshi\n\n");

    printf("Before sorting: ");
    print_number_array(numbers, TOTAL_NUMBERS);
    printf("\n\n");

    qsort(numbers, sizeof(numbers)/sizeof(numbers[0]), sizeof(numbers[0]), compare_numbers);

    printf("After sorting: ");
    print_number_array(numbers, TOTAL_NUMBERS);
    printf("\n\n");

    printf("End of program.\n");
    return 0;
}

void print_number_array(int *array, int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        printf("%d", array[i]);
        if (i < count - 1) printf(", ");
    }
}

int compare_numbers(const void *a, const void *b)
{
    int number_a, number_b;

    number_a = *(int *)a;
    number_b = *(int *)b;

    return number_a - number_b;
}