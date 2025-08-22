#include <stdio.h>

int main(void)
{
    int formula;
    float distance;
    float result;

    printf("Distance Converter.\n\n");
    printf("1. Miles to Kilometers.\n");
    printf("2. Kilometers to Miles.\n");

    printf("\nYour Choice? ");
    scanf("%d", &formula);

    if (formula == 1)
    {
        printf("Enter Miles: ");
        scanf("%f", &distance);
        result = distance * 25146/15625;
        printf("In Kilometers: %f\n", result);
    }
    else if (formula == 2)
    {
        printf("Enter Kilometers: ");
        scanf("%f", &distance);
        result = distance * 15625/25146;
        printf("In Miles: %f\n", result);
    }
    else
    {
        printf("Invalid input.\n");
    }
    
    printf("\nEnd of program.\n");
    return 0;
}