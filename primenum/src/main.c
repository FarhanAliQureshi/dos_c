#include <stdio.h>

const int FALSE = 0;
const int TRUE = 1;

int is_prime(int number);

int main(void)
{
    int start, end, number;

    start = 1;
    end = 100;

    printf("Prime Numbers Between %d and %d.\n\n", start, end);

    for (number = start; number <= end; number++)
    {
        if (is_prime(number) == TRUE)
            printf("%d, ", number);
    }

    printf("\n\nEnd of program.\n");
    return 0;
}

int is_prime(int number)
{
    int i;

    if (number < 2)
        return FALSE;

    for (i = 2; i < number; i++)
    {
        if (number % i == 0)
            return FALSE;
    }

    return TRUE;
}
