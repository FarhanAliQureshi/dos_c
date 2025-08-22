/*

    PROJECT: BISMILLAH
    PROGRAMMER: FARHAN ALI QURESHI
    DESCRIPTION: Display Bismillah with timer and key wait

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <graph.h>
#include <time.h>

#define PROGRAM_BY "Program by FARHAN ALI QURESHI"
#define PRESS_ANY_KEY "(Press any key)"

enum CursorShape {
    NORMAL_CURSOR = 0x0607,
    BLOCK_CURSOR = 0x0007,
    HALF_CURSOR = 0x0407,
    NO_CURSOR = 0x2000
};

int main(int argc, char *argv[])
{
    int previous_fore_color, previous_text_cursor_shape;
    long previous_back_color;
    struct rccoord previous_cursor_pos;
    short previous_display_cursor_mode, previous_wrapon;
    clock_t start_time, current_time;
    double elapsed_time, wait_time;

    // Initialize variables.
    wait_time = 3.0f;           // 3 seconds
    if (argc > 1)
        wait_time = atof(argv[1]);

    // Save current screen info.
    previous_fore_color = _gettextcolor();
    previous_back_color = _getbkcolor();
    previous_cursor_pos = _gettextposition();
    previous_text_cursor_shape = _gettextcursor();

    // Clear screen and display our text.
    _setactivepage(1);
    _setvisualpage(1);
    previous_display_cursor_mode = _displaycursor(_GCURSOROFF);
    _settextcursor(NO_CURSOR);
    _settextcolor(14);
    _setbkcolor(1);
    previous_wrapon = _wrapon(_GWRAPOFF);
    _clearscreen(_GCLEARSCREEN);

    _settextposition(3, 1);
    _outtext("                                                    ²²² ²²²                    \n");
    _outtext("                                               ²²²  ²²² ²²²          ²²²       \n");
    _outtext("                                           ²²² ²²²  ²²² ²²²          ²²²       \n");
    _outtext("                                       ²²²²²²² ²²²  ²²² ²²²      ²²² ²²²       \n");
    _outtext("                                       ²²  ²²² ²²²  ²²² ²²²      ²²² ²²²       \n");
    _outtext("                                       ²²²²²²² ²²²  ²²² ²²²  ²²² ²²² ²²²       \n");
    _outtext("               ²²ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ²²²²²      ²²²²²²²²²²²²      ²²² ²²² ²²²       \n");
    _outtext("                                ²²²²²ÿÿ²²²ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ²²²ÿ²²²ÿ²²²ÿ²²²       \n");
    _outtext("                   ²²²ÿÿÿ²²²²ÿÿÿÿÿ²²²ÿÿ²²²ÿÿ²²²ÿÿÿÿÿ²²²²ÿ²²²ÿ²²²ÿ²²²ÿ²²²       \n");
    _outtext("          ²²²ÿÿÿÿÿÿ²²²²²²²²²²²²²²²²²²ÿÿ²²²ÿÿ²²²ÿ²²²²²²²²²²²²²²²²²²²²²²²²       \n");
    _outtext("          ²²²ÿÿÿÿÿÿ²²²ÿÿÿ²²²²ÿÿÿÿÿÿÿÿÿÿ²²²ÿÿ²²²ÿÿÿÿÿ²²²²                       \n");
    _outtext("          ²²²ÿÿÿÿÿÿ²²²ÿÿÿÿÿÿÿÿÿÿÿÿ²²²ÿÿ²²²ÿÿ²²²ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ²²          \n");
    _outtext("          ²²²²²²²²²²²²ÿÿÿÿÿÿÿ²²²²²²²²²²²²²ÿÿ²²²ÿÿ²²²ÿ²²²                       \n");
    _outtext("          ²²²²²²²²²²²²ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ²²²ÿÿ²²²ÿ²²²                       \n");
    _outtext("                           ²²²²²ÿÿÿÿÿ²²²ÿÿÿÿÿÿÿÿÿ²²²ÿ²²²                       \n");
    _outtext("                      ²²²ÿÿ²²²²²ÿÿÿÿÿ²²²²²²²²²²²²²²²ÿ²²²                       \n");
    _outtext("              ²²²²ÿÿÿÿ²²²ÿÿÿÿ²²²ÿÿÿÿÿ²²²ÿÿÿÿÿÿÿÿÿÿÿÿÿ²²²                       \n");
    _outtext("          ²²²²²²²²²²²²²²²²²²²²²²ÿÿÿÿÿ²²²ÿÿÿÿÿÿÿÿÿÿÿÿÿ²²²                       \n");
    _outtext("              ²²²²ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ²²²²²²²                                       \n");
    _outtext("                    ²²ÿ²²                                                      \n");

    _settextcolor(15);
    _settextposition(25, 3);
    _outtext(PROGRAM_BY);
    _settextposition(25, 80 - strlen(PRESS_ANY_KEY) - 1);
    _outtext(PRESS_ANY_KEY);

    // Empty keyboard buffer.
    while (kbhit()) getch();
    // Wait for timer or if user presses any key.
    start_time = clock();
    while (1)
    {
        if (kbhit()) break;
        current_time = clock();
        elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
        if (elapsed_time >= wait_time) break;
    }
    // If user has pressed an extended key then eat up the next byte because extended key
    // contains two bytes, where first byte is a NUL character.
    if (kbhit())
        if (getch() == 0) 
            getch();

    // Restore previous user screen.
    _setactivepage(0);
    _setvisualpage(0);
    _wrapon(previous_wrapon);
    _settextcolor(previous_fore_color);
    _setbkcolor(previous_back_color);
    _displaycursor(previous_display_cursor_mode);
    _settextcursor(previous_text_cursor_shape);

    // Restore the cursor position.
    _settextposition(previous_cursor_pos.row, previous_cursor_pos.col); 

    return 0;
}
