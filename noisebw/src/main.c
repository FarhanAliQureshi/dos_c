/*

    PROJECT: TV BLACK & WHITE NOISE
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <stdlib.h>
#include <conio.h>
#include <graph.h>
#include <time.h>

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
    int row, col, fore, back;
    int bw_colors[4], total_colors;
    char ch;

        // Initialize variables.
    bw_colors[0] = 0;       // Black
    bw_colors[1] = 7;       // Normal White
    bw_colors[2] = 8;       // Gray
    bw_colors[3] = 15;      // Bright White
    total_colors = sizeof(bw_colors) / sizeof(bw_colors[0]);
    
    // Save current screen info.
    previous_fore_color = _gettextcolor();
    previous_back_color = _getbkcolor();
    previous_cursor_pos = _gettextposition();
    previous_text_cursor_shape = _gettextcursor();

    // Clear screen and display our text.
    _setactivepage(1);
    previous_display_cursor_mode = _displaycursor(_GCURSOROFF);
    _settextcursor(NO_CURSOR);
    _settextcolor(7);
    _setbkcolor(0);
    previous_wrapon = _wrapon(_GWRAPOFF);
    _clearscreen(_GCLEARSCREEN);

    // Initial noise on screen.
    srand(time(NULL));
    ch = 0xDF;
    for (row = 1; row <= 25; row++) 
    {
        for (col = 1; col <= 80; col++)
        {
            fore = rand() % total_colors;
            back = rand() % total_colors;
            _settextcolor(bw_colors[fore]);
            _setbkcolor(bw_colors[back]);
            _settextposition(row, col);
            _outmem(&ch, 1);
        }
    }

    // Display initial colored white noise.
    _setvisualpage(1);

    // Wait for any key.
    while (kbhit()) getch();
    while (!kbhit()) 
    {
        row = (rand() % 25) + 1;
        col = (rand() % 80) + 1;
        fore = rand() % total_colors;
        back = rand() % total_colors;
        _settextcolor(bw_colors[fore]);
        _setbkcolor(bw_colors[back]);
        _settextposition(row, col);
        _outmem(&ch, 1);
    }
    if (getch() == 0) getch();

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
