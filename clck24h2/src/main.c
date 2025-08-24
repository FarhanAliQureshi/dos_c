/*

    PROJECT: BLINKING 24 HOURS CLOCK
    PROGRAMMER: FARHAN ALI QURESHI
    DESCRIPTION: 24 hours clock, formatted as HH:MM:SS with blinking
    separators, and font using extended ASCII characters.

*/

#include <graph.h>
#include <conio.h>
#include <time.h>
#include <i86.h>
#include "common.h"
#include "screen.h"
#include "font.h"
#include "printclk.h"


int main(void)
{
    Font font;
	time_t today;
	struct tm *datetime;
    int row, prev_second, display_separator;
    Screen screen;

    // Initialize variables.
    row = 8;
	tzset();			     			// Reset time zone to empty.
    font = init_font();

    // Prepare screen to display clock.
    init_new_screen(&screen, 1);
    _settextcolor(8);
    _settextposition(25,  3); _outtext("Program by Farhan Ali Qureshi");
    _settextposition(25, 58); _outtext("Press any key to exit");
    _settextcolor(15);
    // print_clock_at(font, row, 88, 88, 88);       // Reset clock.

    // Prepare for blinking separators
    display_separator = FALSE;
    time(&today);
    datetime = localtime(&today);
    prev_second = datetime->tm_sec;

    // Display clock and wait for user to press any key to exit.
    while (kbhit()) getch();
    while (!kbhit())
    {
        time(&today);                   // Get seconds up till now.
        datetime = localtime(&today);   // Convert seconds to date/time.
        if (datetime->tm_sec != prev_second)
        {
            display_separator = TRUE;
            prev_second = datetime->tm_sec;
        }
        print_clock_at(font, row, 
            datetime->tm_hour, datetime->tm_min, datetime->tm_sec,
            display_separator);
        if (display_separator == TRUE)
        {
            display_separator = FALSE;
            delay(500);
        }
    }
    if (getch() == 0) getch();

    // Cleanup.
    restore_screen(&screen);
    destroy_font(font);

    return 0;
}
