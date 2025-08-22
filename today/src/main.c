/*

    PROJECT: TODAY
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char format[81], today[81], suffix[3];
	time_t todaytime;
	struct tm *datetime;

	// Get current date/time.
	tzset();			     			// Reset time zone to empty.
	time(&todaytime);                   // Get seconds up till now.
	datetime = localtime(&todaytime);   // Convert seconds to date/time.

    // Prepare suffix for day of the month.
    switch (datetime->tm_mday)
    {
        case 1:
        case 21:
        case 31:
            strcpy(suffix, "st");
            break;
        case 2:
        case 22:
            strcpy(suffix, "nd");
            break;
        case 3:
        case 23:
            strcpy(suffix, "rd");
            break;
        default:
            strcpy(suffix, "th");
            break;        
    }

    // Format for today string.
	sprintf(format, "Today is %%A, %%d%s of %%B, %%Y. Current Time is %%I:%%M %%p.", suffix);

    // Get date/time using format.
    strftime(today, sizeof(today), format, datetime);

	// Display date/time on User screen.
	printf("%s\n", today);

	// Exit to OS.
    return 0;
}
