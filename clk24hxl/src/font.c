#include <string.h>
#include <malloc.h>
#include "font.h"

void init_characters(Font array)
{
    // 0
    strcpy(array[ 0].line[ 0], "ллллллллллллллллл");
    strcpy(array[ 0].line[ 1], "лл             лл");
    strcpy(array[ 0].line[ 2], "лл             лл");
    strcpy(array[ 0].line[ 3], "лл             лл");
    strcpy(array[ 0].line[ 4], "лл             лл");
    strcpy(array[ 0].line[ 5], "лл             лл");
    strcpy(array[ 0].line[ 6], "лл             лл");
    strcpy(array[ 0].line[ 7], "лл             лл");
    strcpy(array[ 0].line[ 8], "лл             лл");
    strcpy(array[ 0].line[ 9], "лл             лл");
    strcpy(array[ 0].line[10], "лл             лл");
    strcpy(array[ 0].line[11], "лл             лл");
    strcpy(array[ 0].line[12], "лл             лл");
    strcpy(array[ 0].line[13], "лл             лл");
    strcpy(array[ 0].line[14], "лл             лл");
    strcpy(array[ 0].line[15], "лл             лл");
    strcpy(array[ 0].line[16], "лл             лл");
    strcpy(array[ 0].line[17], "лл             лл");
    strcpy(array[ 0].line[18], "ллллллллллллллллл");

    // 1
    strcpy(array[ 1].line[ 0], "               лл");
    strcpy(array[ 1].line[ 1], "               лл");
    strcpy(array[ 1].line[ 2], "               лл");
    strcpy(array[ 1].line[ 3], "               лл");
    strcpy(array[ 1].line[ 4], "               лл");
    strcpy(array[ 1].line[ 5], "               лл");
    strcpy(array[ 1].line[ 6], "               лл");
    strcpy(array[ 1].line[ 7], "               лл");
    strcpy(array[ 1].line[ 8], "               лл");
    strcpy(array[ 1].line[ 9], "               лл");
    strcpy(array[ 1].line[10], "               лл");
    strcpy(array[ 1].line[11], "               лл");
    strcpy(array[ 1].line[12], "               лл");
    strcpy(array[ 1].line[13], "               лл");
    strcpy(array[ 1].line[14], "               лл");
    strcpy(array[ 1].line[15], "               лл");
    strcpy(array[ 1].line[16], "               лл");
    strcpy(array[ 1].line[17], "               лл");
    strcpy(array[ 1].line[18], "               лл");

    // 2
    strcpy(array[ 2].line[ 0], "ллллллллллллллллл");
    strcpy(array[ 2].line[ 1], "               лл");
    strcpy(array[ 2].line[ 2], "               лл");
    strcpy(array[ 2].line[ 3], "               лл");
    strcpy(array[ 2].line[ 4], "               лл");
    strcpy(array[ 2].line[ 5], "               лл");
    strcpy(array[ 2].line[ 6], "               лл");
    strcpy(array[ 2].line[ 7], "               лл");
    strcpy(array[ 2].line[ 8], "               лл");
    strcpy(array[ 2].line[ 9], "ллллллллллллллллл");
    strcpy(array[ 2].line[10], "лл               ");
    strcpy(array[ 2].line[11], "лл               ");
    strcpy(array[ 2].line[12], "лл               ");
    strcpy(array[ 2].line[13], "лл               ");
    strcpy(array[ 2].line[14], "лл               ");
    strcpy(array[ 2].line[15], "лл               ");
    strcpy(array[ 2].line[16], "лл               ");
    strcpy(array[ 2].line[17], "лл               ");
    strcpy(array[ 2].line[18], "ллллллллллллллллл");

    // 3
    strcpy(array[ 3].line[ 0], "ллллллллллллллллл");
    strcpy(array[ 3].line[ 1], "               лл");
    strcpy(array[ 3].line[ 2], "               лл");
    strcpy(array[ 3].line[ 3], "               лл");
    strcpy(array[ 3].line[ 4], "               лл");
    strcpy(array[ 3].line[ 5], "               лл");
    strcpy(array[ 3].line[ 6], "               лл");
    strcpy(array[ 3].line[ 7], "               лл");
    strcpy(array[ 3].line[ 8], "               лл");
    strcpy(array[ 3].line[ 9], "ллллллллллллллллл");
    strcpy(array[ 3].line[10], "               лл");
    strcpy(array[ 3].line[11], "               лл");
    strcpy(array[ 3].line[12], "               лл");
    strcpy(array[ 3].line[13], "               лл");
    strcpy(array[ 3].line[14], "               лл");
    strcpy(array[ 3].line[15], "               лл");
    strcpy(array[ 3].line[16], "               лл");
    strcpy(array[ 3].line[17], "               лл");
    strcpy(array[ 3].line[18], "ллллллллллллллллл");
    
    // 4
    strcpy(array[ 4].line[ 0], "лл             лл");
    strcpy(array[ 4].line[ 1], "лл             лл");
    strcpy(array[ 4].line[ 2], "лл             лл");
    strcpy(array[ 4].line[ 3], "лл             лл");
    strcpy(array[ 4].line[ 4], "лл             лл");
    strcpy(array[ 4].line[ 5], "лл             лл");
    strcpy(array[ 4].line[ 6], "лл             лл");
    strcpy(array[ 4].line[ 7], "лл             лл");
    strcpy(array[ 4].line[ 8], "лл             лл");
    strcpy(array[ 4].line[ 9], "ллллллллллллллллл");
    strcpy(array[ 4].line[10], "               лл");
    strcpy(array[ 4].line[11], "               лл");
    strcpy(array[ 4].line[12], "               лл");
    strcpy(array[ 4].line[13], "               лл");
    strcpy(array[ 4].line[14], "               лл");
    strcpy(array[ 4].line[15], "               лл");
    strcpy(array[ 4].line[16], "               лл");
    strcpy(array[ 4].line[17], "               лл");
    strcpy(array[ 4].line[18], "               лл");
    
    // 5
    strcpy(array[ 5].line[ 0], "ллллллллллллллллл");
    strcpy(array[ 5].line[ 1], "лл               ");
    strcpy(array[ 5].line[ 2], "лл               ");
    strcpy(array[ 5].line[ 3], "лл               ");
    strcpy(array[ 5].line[ 4], "лл               ");
    strcpy(array[ 5].line[ 5], "лл               ");
    strcpy(array[ 5].line[ 6], "лл               ");
    strcpy(array[ 5].line[ 7], "лл               ");
    strcpy(array[ 5].line[ 8], "лл               ");
    strcpy(array[ 5].line[ 9], "ллллллллллллллллл");
    strcpy(array[ 5].line[10], "               лл");
    strcpy(array[ 5].line[11], "               лл");
    strcpy(array[ 5].line[12], "               лл");
    strcpy(array[ 5].line[13], "               лл");
    strcpy(array[ 5].line[14], "               лл");
    strcpy(array[ 5].line[15], "               лл");
    strcpy(array[ 5].line[16], "               лл");
    strcpy(array[ 5].line[17], "               лл");
    strcpy(array[ 5].line[18], "ллллллллллллллллл");
    
    // 6
    strcpy(array[ 6].line[ 0], "ллллллллллллллллл");
    strcpy(array[ 6].line[ 1], "лл               ");
    strcpy(array[ 6].line[ 2], "лл               ");
    strcpy(array[ 6].line[ 3], "лл               ");
    strcpy(array[ 6].line[ 4], "лл               ");
    strcpy(array[ 6].line[ 5], "лл               ");
    strcpy(array[ 6].line[ 6], "лл               ");
    strcpy(array[ 6].line[ 7], "лл               ");
    strcpy(array[ 6].line[ 8], "лл               ");
    strcpy(array[ 6].line[ 9], "ллллллллллллллллл");
    strcpy(array[ 6].line[10], "лл             лл");
    strcpy(array[ 6].line[11], "лл             лл");
    strcpy(array[ 6].line[12], "лл             лл");
    strcpy(array[ 6].line[13], "лл             лл");
    strcpy(array[ 6].line[14], "лл             лл");
    strcpy(array[ 6].line[15], "лл             лл");
    strcpy(array[ 6].line[16], "лл             лл");
    strcpy(array[ 6].line[17], "лл             лл");
    strcpy(array[ 6].line[18], "ллллллллллллллллл");
    
    // 7
    strcpy(array[ 7].line[ 0], "ллллллллллллллллл");
    strcpy(array[ 7].line[ 1], "               лл");
    strcpy(array[ 7].line[ 2], "               лл");
    strcpy(array[ 7].line[ 3], "               лл");
    strcpy(array[ 7].line[ 4], "               лл");
    strcpy(array[ 7].line[ 5], "               лл");
    strcpy(array[ 7].line[ 6], "               лл");
    strcpy(array[ 7].line[ 7], "               лл");
    strcpy(array[ 7].line[ 8], "               лл");
    strcpy(array[ 7].line[ 9], "               лл");
    strcpy(array[ 7].line[10], "               лл");
    strcpy(array[ 7].line[11], "               лл");
    strcpy(array[ 7].line[12], "               лл");
    strcpy(array[ 7].line[13], "               лл");
    strcpy(array[ 7].line[14], "               лл");
    strcpy(array[ 7].line[15], "               лл");
    strcpy(array[ 7].line[16], "               лл");
    strcpy(array[ 7].line[17], "               лл");
    strcpy(array[ 7].line[18], "               лл");

    // 8
    strcpy(array[ 8].line[ 0], "ллллллллллллллллл");
    strcpy(array[ 8].line[ 1], "лл             лл");
    strcpy(array[ 8].line[ 2], "лл             лл");
    strcpy(array[ 8].line[ 3], "лл             лл");
    strcpy(array[ 8].line[ 4], "лл             лл");
    strcpy(array[ 8].line[ 5], "лл             лл");
    strcpy(array[ 8].line[ 6], "лл             лл");
    strcpy(array[ 8].line[ 7], "лл             лл");
    strcpy(array[ 8].line[ 8], "лл             лл");
    strcpy(array[ 8].line[ 9], "ллллллллллллллллл");
    strcpy(array[ 8].line[10], "лл             лл");
    strcpy(array[ 8].line[11], "лл             лл");
    strcpy(array[ 8].line[12], "лл             лл");
    strcpy(array[ 8].line[13], "лл             лл");
    strcpy(array[ 8].line[14], "лл             лл");
    strcpy(array[ 8].line[15], "лл             лл");
    strcpy(array[ 8].line[16], "лл             лл");
    strcpy(array[ 8].line[17], "лл             лл");
    strcpy(array[ 8].line[18], "ллллллллллллллллл");

    // 9
    strcpy(array[ 9].line[ 0], "ллллллллллллллллл");
    strcpy(array[ 9].line[ 1], "лл             лл");
    strcpy(array[ 9].line[ 2], "лл             лл");
    strcpy(array[ 9].line[ 3], "лл             лл");
    strcpy(array[ 9].line[ 4], "лл             лл");
    strcpy(array[ 9].line[ 5], "лл             лл");
    strcpy(array[ 9].line[ 6], "лл             лл");
    strcpy(array[ 9].line[ 7], "лл             лл");
    strcpy(array[ 9].line[ 8], "лл             лл");
    strcpy(array[ 9].line[ 9], "ллллллллллллллллл");
    strcpy(array[ 9].line[10], "               лл");
    strcpy(array[ 9].line[11], "               лл");
    strcpy(array[ 9].line[12], "               лл");
    strcpy(array[ 9].line[13], "               лл");
    strcpy(array[ 9].line[14], "               лл");
    strcpy(array[ 9].line[15], "               лл");
    strcpy(array[ 9].line[16], "               лл");
    strcpy(array[ 9].line[17], "               лл");
    strcpy(array[ 9].line[18], "               лл");

    // : as Separator
    strcpy(array[10].line[ 0], "      ");
    strcpy(array[10].line[ 1], "      ");
    strcpy(array[10].line[ 2], "      ");
    strcpy(array[10].line[ 3], "      ");
    strcpy(array[10].line[ 4], "  лл  ");
    strcpy(array[10].line[ 5], "  лл  ");
    strcpy(array[10].line[ 6], "      ");
    strcpy(array[10].line[ 7], "      ");
    strcpy(array[10].line[ 8], "      ");
    strcpy(array[10].line[ 9], "      ");
    strcpy(array[10].line[10], "      ");
    strcpy(array[10].line[11], "      ");
    strcpy(array[10].line[12], "      ");
    strcpy(array[10].line[13], "  лл  ");
    strcpy(array[10].line[14], "  лл  ");
    strcpy(array[10].line[15], "      ");
    strcpy(array[10].line[16], "      ");
    strcpy(array[10].line[17], "      ");
    strcpy(array[10].line[18], "      ");

    // Blank Separator
    strcpy(array[11].line[ 0], "      ");
    strcpy(array[11].line[ 1], "      ");
    strcpy(array[11].line[ 2], "      ");
    strcpy(array[11].line[ 3], "      ");
    strcpy(array[11].line[ 4], "      ");
    strcpy(array[11].line[ 5], "      ");
    strcpy(array[11].line[ 6], "      ");
    strcpy(array[11].line[ 7], "      ");
    strcpy(array[11].line[ 8], "      ");
    strcpy(array[11].line[ 9], "      ");
    strcpy(array[11].line[10], "      ");
    strcpy(array[11].line[11], "      ");
    strcpy(array[11].line[12], "      ");
    strcpy(array[11].line[13], "      ");
    strcpy(array[11].line[14], "      ");
    strcpy(array[11].line[15], "      ");
    strcpy(array[11].line[16], "      ");
    strcpy(array[11].line[17], "      ");
    strcpy(array[11].line[18], "      ");
}

Font init_font()
{
    Font font;
    font = (Font)malloc(sizeof(Character) * TOTAL_CHARACTERS);
    init_characters(font);

    return font;
}

void destroy_font(Font font)
{
    free(font);
}
