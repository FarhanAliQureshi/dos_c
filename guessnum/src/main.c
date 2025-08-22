/*

    PROJECT: GUESS THE NUMBER
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int number, input, result;

    srand(time(NULL));
    number = (rand() % 100) + 1;

    printf("GUESS THE NUMBER\n");
    printf("Program by Farhan Ali Qureshi\n\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("Enter 0 to quit game.\n");

    while (1)
    {
        printf("Your guess: ");
        result = scanf("%d", &input);
        if (result == EOF || result == 0) {
            scanf("%s");
            printf("Invalid input.\n");
            continue;
        }
        if (input == 0)  {
            break;
        }
        else if (input < 1 || input > 100) {
            printf("The number I selected is between 1 and 100.\n");
        }
        else if (input < number) {
            printf("The number I selected is higher than %d.\n", input);
        }
        else if (input > number) {
            printf("The number I selected is lower than %d.\n", input);
        }
        else {
            printf("YOU WON! The number is %d.\n\n", number);
            break;
        }
    }

    printf("End of program.\n");
    return 0;
}
