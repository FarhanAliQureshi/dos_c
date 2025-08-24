/*

    PROJECT: STOP WATCH WITH ELAPSED TIME
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>

#define ERASER_SIZE 33

int main(void)
{
    clock_t start_time, end_time, interval_time;
    double elapsed_time;
    char eraser[ERASER_SIZE];

    memset(eraser, ' ', ERASER_SIZE);
    eraser[ERASER_SIZE - 1] = 0x00;

    printf("STOP WATCH WITH ELAPSED TIME\n");
    printf("Program by Farhan Ali Qureshi\n\n");

    printf("Press any key to start stopwatch...");
    fflush(stdout);
    while (kbhit()) getch();
    while (!kbhit()) {}
    if (getch() == 0) getch();
    start_time = clock();

    printf("\n\nStopwatch started!\nPress any key to stop stopwatch...\n");
    fflush(stdout);
    while (kbhit()) getch();
    while (!kbhit()) 
    {
        interval_time = clock();
        elapsed_time = (double)(interval_time - start_time) / CLOCKS_PER_SEC;
        printf("\r%.4f", elapsed_time);
        fflush(stdout);
    }
    if (getch() == 0) getch();

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\r%s", eraser);
    printf("\nStopwatch Time: %.4f seconds\n", elapsed_time);

    return 0;
}
