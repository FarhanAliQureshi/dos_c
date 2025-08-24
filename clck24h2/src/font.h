#ifndef FONT_H
#define FONT_H

#define CHAR_MAX_LINES 9
#define CHAR_MAX_WIDTH 9
#define TOTAL_CHARACTERS 12

#define CHAR_0 0
#define CHAR_1 1
#define CHAR_2 2
#define CHAR_3 3
#define CHAR_4 4
#define CHAR_5 5
#define CHAR_6 6
#define CHAR_7 7
#define CHAR_8 8
#define CHAR_9 9
#define CHAR_SEPARATOR 10
#define CHAR_SEPARATOR_BLANK 11

struct character_glyph
{
    char line[CHAR_MAX_LINES][CHAR_MAX_WIDTH];
};
typedef struct character_glyph Character, *Font;

Font init_font();
void destroy_font(Font font);

#endif
