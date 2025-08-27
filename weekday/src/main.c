/*

    PROJECT: DETERMINE WEEK DAY
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char buffer[81];
	time_t utc_time;
	struct tm *datetime, input;

    memset(&input, 0, sizeof(struct tm));
    printf("FIND DAY OF WEEK OF A DATE\n");
    printf("Program by Farhan Ali Qureshi\n\n");

    printf("Day (DD): ");
    fflush(stdout);
    gets(buffer);
    buffer[80] = 0x00;
    input.tm_mday = atoi(buffer);           // 1 to 31

    printf("Month (MM): ");
    fflush(stdout);
    gets(buffer);
    buffer[80] = 0x00;
    input.tm_mon = atoi(buffer) - 1;        // 0 to 11

    printf("Year (YYYY): ");
    fflush(stdout);
    gets(buffer);
    buffer[80] = 0x00;
    input.tm_year = atoi(buffer) - 1900;    // Years since 1900

	// Find day of the week.
    utc_time = mktime(&input);
	datetime = localtime(&utc_time);

    // Print date using format.
    strftime(buffer, sizeof(buffer) / sizeof(char), "Date is %A, %B %d, %Y", datetime);
	printf("\n%s\n", buffer);

    return 0;
}
