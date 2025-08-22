/*

    PROJECT: BISMILLAH
    PROGRAMMER: FARHAN ALI QURESHI
    DESCRIPTION: Display Bismillah with key wait

*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <graph.h>

#define PROGRAM_BY "Program by FARHAN ALI QURESHI"
#define PRESS_ANY_KEY "(Press any key)"

enum CursorShape {
    NORMAL_CURSOR = 0x0607,
    BLOCK_CURSOR = 0x0007,
    HALF_CURSOR = 0x0407,
    NO_CURSOR = 0x2000
};

int main(void)
{
    int previous_fore_color, previous_text_cursor_shape;
    long previous_back_color;
    struct rccoord previous_cursor_pos;
    short previous_display_cursor_mode, previous_wrapon;

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
    _outtext("                                                    ��� ���                    \n");
    _outtext("                                               ���  ��� ���          ���       \n");
    _outtext("                                           ��� ���  ��� ���          ���       \n");
    _outtext("                                       ������� ���  ��� ���      ��� ���       \n");
    _outtext("                                       ��  ��� ���  ��� ���      ��� ���       \n");
    _outtext("                                       ������� ���  ��� ���  ��� ��� ���       \n");
    _outtext("               ����������������������      ������������      ��� ��� ���       \n");
    _outtext("                                ����������������������������������������       \n");
    _outtext("                   �����������������������������������������������������       \n");
    _outtext("          ��������������������������������������������������������������       \n");
    _outtext("          ����������������������������������������������                       \n");
    _outtext("          �����������������������������������������������������������          \n");
    _outtext("          ����������������������������������������������                       \n");
    _outtext("          ����������������������������������������������                       \n");
    _outtext("                           �����������������������������                       \n");
    _outtext("                      ����������������������������������                       \n");
    _outtext("              ������������������������������������������                       \n");
    _outtext("          ����������������������������������������������                       \n");
    _outtext("              ��������������������������                                       \n");
    _outtext("                    �����                                                      \n");

    _settextcolor(15);
    _settextposition(25, 3);
    _outtext(PROGRAM_BY);
    _settextposition(25, 80 - strlen(PRESS_ANY_KEY) - 1);
    _outtext(PRESS_ANY_KEY);

    // Wait for user to press any key.
    while (kbhit()) getch();            // Empty keyboard buffer.
    while (!kbhit()) {}                 // Wait for user to press any key.
    if (getch() == 0) getch();          // If user has pressed an extended key then
                                        // eat up the next byte because extended key
                                        // contains two bytes, where first byte is a 
                                        // NUL character.

    // Restore old screen.
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
