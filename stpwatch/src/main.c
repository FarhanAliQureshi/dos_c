/*

    PROJECT: STOP WATCH
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <stdio.h>
#include <time.h>
#include <conio.h>

void wait_for_any_key(void);

int main(void)
{
    clock_t start_time, end_time;
    double elapsed_time;

    printf("STOPWATCH\n");
    printf("Program by Farhan Ali Qureshi\n\n");

    printf("Press any key to start stopwatch...");
    fflush(stdout);
    wait_for_any_key();
    start_time = clock();

    printf("\n\nStopwatch started!\nPress any key to stop stopwatch...");
    fflush(stdout);
    wait_for_any_key();
    end_time = clock();

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\n\nStopwatch Time: %f seconds\n", elapsed_time);

    return 0;
}

void wait_for_any_key(void)
{
    while (kbhit()) getch();
    while (!kbhit()) {}
    if (getch() == 0) getch();
    return;
}

