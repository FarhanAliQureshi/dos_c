#include <graph.h>
#include "common.h"
#include "printclk.h"

void print_char_at(Character *ch, int row, int col);
void print_digit_pair_at(Font font, int row, int col, int digit_pair);
void print_separator_at(Font font, int row, int col, int show_separator);

void print_char_at(Character *ch, int row, int col)
{
    int i;    
    for (i = 0; i < CHAR_MAX_LINES; i++)
    {
        _settextposition(row + i, col);
        _outtext(ch->line[i]);
    }
}

void print_digit_pair_at(Font font, int row, int col, int digit_pair)
{
    int digit1, digit2, pos;

    pos = 0;
    if (digit_pair < 10)
    {
        digit1 = 0;
        digit2 = digit_pair;
    }
    else
    {
        digit1 = digit_pair / 10;
        digit2 = digit_pair % 10;
    }

    print_char_at(&font[digit1], row, 
        col + ((CHAR_MAX_WIDTH + 1) * pos++));
    print_char_at(&font[digit2], row, 
        col + ((CHAR_MAX_WIDTH + 1) * pos++));
}

void print_separator_at(Font font, int row, int col, int show_separator)
{
    if (show_separator == TRUE)
        print_char_at(&font[CHAR_SEPARATOR], row, col);
    else
        print_char_at(&font[CHAR_SEPARATOR_BLANK], row, col);
}

void print_clock_at(Font font, int row, int hour, int minute, int second, int show_separator)
{
    print_digit_pair_at(font, row, 8, hour);          // Hours
    print_digit_pair_at(font, row, 32, minute);       // Minutes
    print_digit_pair_at(font, row, 56, second);       // Seconds
    // Separators
    print_separator_at(font, row, 26, show_separator);
    print_separator_at(font, row, 50, show_separator);
}
