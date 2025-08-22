#include <stdio.h>

int main(void)
{
    int number;

    printf("Is it an Even number or an Odd number?\n\n");

    for (number = 1; number < 10; number++)
    {
        if (number % 2 == 0)
            printf("%d is an Even number.\n", number);
        else
            printf("%d is an Odd number.\n", number);
    }

    printf("\nEnd of program.\n");
    return 0;
}