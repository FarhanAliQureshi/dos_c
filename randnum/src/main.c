/*

    PROJECT: RANDOM NUMBER
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int number;

    printf("Random Number Between 1 and 100.\n\n");

    srand(time(NULL));
    number = (rand() % 100) + 1;

    printf("Number: %d\n", number);

    return 0;
}
