#include <stdio.h>

int main(void)
{
    int choice;
    float temperature;
    float converted;

    printf("Celsius to Fahrenheit (and vice versa) Converter.\n\n");
    printf("1. Celsius to Fahrenheit.\n");
    printf("2. Fahrenheit to Celsius.\n");

    printf("\nYour Choice? ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter Celsius Temperature: ");
        scanf("%f", &temperature);
        converted = (temperature * 9/5) + 32;
        printf("In Fahrenheit: %f\n", converted);
    }
    else if (choice == 2)
    {
        printf("Enter Fahrenheit Temperature: ");
        scanf("%f", &temperature);
        converted = (temperature - 32) * 5/9;
        printf("In Celsius: %f\n", converted);
    }
    else
    {
        printf("Invalid input. Exiting to DOS.\n");
    }
    
    printf("\nEnd of program.\n");
    return 0;
}