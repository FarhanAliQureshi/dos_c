/*

    PROJECT: NAME OF ALLAH
    PROGRAMMER: FARHAN ALI QURESHI
    DESCRIPTION: Display name of Allah, with sparkles in background,
    and wait for any key

*/

#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <graph.h>
#include <time.h>

#define PROGRAM_BY "џProgramџbyџFARHANџALIџQURESHIџ"
#define PRESS_ANY_KEY "џ(Pressџanyџkey)џ"

enum CursorShape {
    NORMAL_CURSOR = 0x0607,
    BLOCK_CURSOR = 0x0007,
    HALF_CURSOR = 0x0407,
    NO_CURSOR = 0x2000
};

int main(void)
{
    int row, col, fore, back;
    int bw_colors[2], total_colors, total_sparkles, memory_index;
    unsigned char sparkles[3], ch;
    unsigned char far *text_memory;

    // Initialize variables.
    bw_colors[0] = 0;       // Black
    bw_colors[1] = 8;       // Gray
    total_colors = sizeof(bw_colors) / sizeof(bw_colors[0]);
    sparkles[0] = 'п';
    sparkles[1] = 'м';
    sparkles[2] = 'ў';
    total_sparkles = sizeof(sparkles) / sizeof(sparkles[0]);

    // To directly access memory of text mode
    text_memory = (unsigned char far*) 0xB8000000;

    // Prepare screen to display.
    _setvideomode(_TEXTC80);
    _settextrows(25);
    _displaycursor(_GCURSOROFF);
    _settextcursor(NO_CURSOR);
    _wrapon(_GWRAPOFF);
    _settextcolor(15);
    _setbkcolor(0);
    _clearscreen(_GCLEARSCREEN);

    // Display name.
    row = 5; col = 21;
    _settextposition(row++, col); _outtext("                 л л л ");
    _settextposition(row++, col); _outtext("                 ллллл ");
    _settextposition(row++, col); _outtext("                          ллллл   ллллл");
    _settextposition(row++, col); _outtext("                 ллллл    ллллл   ллллл");
    _settextposition(row++, col); _outtext("        ллллл    ллллл    ллллл   ллллл");
    _settextposition(row++, col); _outtext("        ллллл    ллллл    ллллл   ллллл");
    _settextposition(row++, col); _outtext("        ллллл    ллллл    ллллл   ллллл");
    _settextposition(row++, col); _outtext("        ллллл    ллллл    ллллл   ллллл");
    _settextposition(row++, col); _outtext("ллллллллллллл    ллллл    ллллл   ллллл");
    _settextposition(row++, col); _outtext("лллл    ллллл    ллллл    ллллл   ллллл");
    _settextposition(row++, col); _outtext("лллл    ллллл    ллллл    ллллл   ллллл");
    _settextposition(row++, col); _outtext("лллл    ллллл    ллллл    ллллл   ллллл");
    _settextposition(row++, col); _outtext("ллллллллллллл    ллллл    ллллл   ллллл");
    _settextposition(row++, col); _outtext("        ллллллллллллллллллллллл");
    _settextposition(row++, col); _outtext("        ллллллллллллллллллллллл");

    // Put artist's name.
    _settextcolor(8);
    _settextposition(25, 3);
    _outtext(PROGRAM_BY);
    _settextposition(25, 80 - strlen(PRESS_ANY_KEY) - 1);
    _outtext(PRESS_ANY_KEY);

    // Wait for user to press any key.
    srand(time(NULL));
    while (kbhit()) getch();
    while (!kbhit()) 
    {
        // Randomly put sparkles in background.
        row = (rand() % 25) + 1;
        col = (rand() % 80) + 1;
        memory_index = (row - 1) * 80;
        memory_index += (col - 1);
        memory_index *= 2;
        switch (text_memory[memory_index])
        {
            case ' ':
            case 'п':
            case 'м':
            case 'ў':
            fore = rand() % total_colors;
            back = rand() % total_colors;
            _settextcolor(bw_colors[fore]);
            _setbkcolor(bw_colors[back]);
            _settextposition(row, col);
            ch = sparkles[rand() % total_sparkles];
            _outmem(&ch, 1);
        }
    }
    if (getch() == 0) getch();

    // Cleanup before exiting.
    _wrapon(_GWRAPON);
    _settextcolor(7);
    _setbkcolor(0);
    _displaycursor(_GCURSORON);
    _settextcursor(NORMAL_CURSOR);
    _clearscreen(_GCLEARSCREEN);

    return 0;
}
