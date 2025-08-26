#include <graph.h>
#include <string.h>
#include "pritxt.h"

void clear_row(int row, char *eraser)
{
    _settextposition(row, 1);
    _outtext(eraser);
}

// If col == 0 then center the text in that row
void pri(int row, int col, char *text)
{
    int length, calculated_col;

    if (col == 0)
    {
        length = strlen(text);
        calculated_col = (80 - length) / 2;
    }
    else
    {
        calculated_col = col;
    }
    _settextposition(row, calculated_col);
    _outtext(text);
}

void pricolor(int row, int col, int fore, int back, char *text)
{
    _settextcolor(fore);
    _setbkcolor(back);
    pri(row, col, text);
}
