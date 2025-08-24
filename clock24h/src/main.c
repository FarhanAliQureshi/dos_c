/*

    PROJECT: 24 HOURS CLOCK HH:MM:SS
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <graph.h>
#include <conio.h>
#include <time.h>
#include "common.h"
#include "font.h"
#include "printclk.h"

int main(void)
{
    Font font;
	time_t today;
	struct tm *datetime;
    int row, prev_cursor_mode, prev_cursor_shape;

    // Initialize variables.
    row = 8;
	tzset();			     			// Reset time zone to empty.
    font = init_font();

    // Prepare screen to display clock.
    prev_cursor_mode = _displaycursor(_GCURSOROFF);
    prev_cursor_shape = _gettextcursor();
    _settextcursor(NO_CURSOR);
    _clearscreen(_GCLEARSCREEN);
    _settextposition(25,  3); _outtext("Program by Farhan Ali Qureshi");
    _settextposition(25, 58); _outtext("Press any key to exit");
    // print_clock_at(font, row, 88, 88, 88);       // Reset clock.

    // Display clock and wait for user to press any key to exit.
    while (kbhit()) getch();
    while (!kbhit())
    {
        time(&today);                   // Get seconds up till now.
        datetime = localtime(&today);   // Convert seconds to date/time.
        print_clock_at(font, row, 
            datetime->tm_hour, datetime->tm_min, datetime->tm_sec);
    }
    if (getch() == 0) getch();

    // Cleanup.
    _displaycursor(prev_cursor_mode);
    _settextcursor(prev_cursor_shape);
    _clearscreen(_GCLEARSCREEN);
    destroy_font(font);

    return 0;
}
