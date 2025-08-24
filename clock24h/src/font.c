#include <string.h>
#include <malloc.h>
#include "font.h"

void init_characters(Font array)
{
    // 0
    strcpy(array[0].line[0], "########");
    strcpy(array[0].line[1], "#      #");
    strcpy(array[0].line[2], "#      #");
    strcpy(array[0].line[3], "#      #");
    strcpy(array[0].line[4], "#      #");
    strcpy(array[0].line[5], "#      #");
    strcpy(array[0].line[6], "#      #");
    strcpy(array[0].line[7], "#      #");
    strcpy(array[0].line[8], "########");

    // 1
    strcpy(array[1].line[0], "       #");
    strcpy(array[1].line[1], "       #");
    strcpy(array[1].line[2], "       #");
    strcpy(array[1].line[3], "       #");
    strcpy(array[1].line[4], "       #");
    strcpy(array[1].line[5], "       #");
    strcpy(array[1].line[6], "       #");
    strcpy(array[1].line[7], "       #");
    strcpy(array[1].line[8], "       #");

    // 2
    strcpy(array[2].line[0], "########");
    strcpy(array[2].line[1], "       #");
    strcpy(array[2].line[2], "       #");
    strcpy(array[2].line[3], "       #");
    strcpy(array[2].line[4], "########");
    strcpy(array[2].line[5], "#       ");
    strcpy(array[2].line[6], "#       ");
    strcpy(array[2].line[7], "#       ");
    strcpy(array[2].line[8], "########");

    // 3
    strcpy(array[3].line[0], "########");
    strcpy(array[3].line[1], "       #");
    strcpy(array[3].line[2], "       #");
    strcpy(array[3].line[3], "       #");
    strcpy(array[3].line[4], "########");
    strcpy(array[3].line[5], "       #");
    strcpy(array[3].line[6], "       #");
    strcpy(array[3].line[7], "       #");
    strcpy(array[3].line[8], "########");
    
    // 4
    strcpy(array[4].line[0], "#      #");
    strcpy(array[4].line[1], "#      #");
    strcpy(array[4].line[2], "#      #");
    strcpy(array[4].line[3], "#      #");
    strcpy(array[4].line[4], "########");
    strcpy(array[4].line[5], "       #");
    strcpy(array[4].line[6], "       #");
    strcpy(array[4].line[7], "       #");
    strcpy(array[4].line[8], "       #");
    
    // 5
    strcpy(array[5].line[0], "########");
    strcpy(array[5].line[1], "#       ");
    strcpy(array[5].line[2], "#       ");
    strcpy(array[5].line[3], "#       ");
    strcpy(array[5].line[4], "########");
    strcpy(array[5].line[5], "       #");
    strcpy(array[5].line[6], "       #");
    strcpy(array[5].line[7], "       #");
    strcpy(array[5].line[8], "########");
    
    // 6
    strcpy(array[6].line[0], "########");
    strcpy(array[6].line[1], "#       ");
    strcpy(array[6].line[2], "#       ");
    strcpy(array[6].line[3], "#       ");
    strcpy(array[6].line[4], "########");
    strcpy(array[6].line[5], "#      #");
    strcpy(array[6].line[6], "#      #");
    strcpy(array[6].line[7], "#      #");
    strcpy(array[6].line[8], "########");
    
    // 7
    strcpy(array[7].line[0], "########");
    strcpy(array[7].line[1], "       #");
    strcpy(array[7].line[2], "       #");
    strcpy(array[7].line[3], "       #");
    strcpy(array[7].line[4], "       #");
    strcpy(array[7].line[5], "       #");
    strcpy(array[7].line[6], "       #");
    strcpy(array[7].line[7], "       #");
    strcpy(array[7].line[8], "       #");

    // 8
    strcpy(array[8].line[0], "########");
    strcpy(array[8].line[1], "#      #");
    strcpy(array[8].line[2], "#      #");
    strcpy(array[8].line[3], "#      #");
    strcpy(array[8].line[4], "########");
    strcpy(array[8].line[5], "#      #");
    strcpy(array[8].line[6], "#      #");
    strcpy(array[8].line[7], "#      #");
    strcpy(array[8].line[8], "########");

    // 9
    strcpy(array[9].line[0], "########");
    strcpy(array[9].line[1], "#      #");
    strcpy(array[9].line[2], "#      #");
    strcpy(array[9].line[3], "#      #");
    strcpy(array[9].line[4], "########");
    strcpy(array[9].line[5], "       #");
    strcpy(array[9].line[6], "       #");
    strcpy(array[9].line[7], "       #");
    strcpy(array[9].line[8], "       #");

    // :
    // strcpy(array[10].line[0], "        ");
    // strcpy(array[10].line[1], "        ");
    // strcpy(array[10].line[2], "   ##   ");
    // strcpy(array[10].line[3], "   ##   ");
    // strcpy(array[10].line[4], "        ");
    // strcpy(array[10].line[5], "   ##   ");
    // strcpy(array[10].line[6], "   ##   ");
    // strcpy(array[10].line[7], "        ");
    // strcpy(array[10].line[8], "        ");

    // :
    strcpy(array[10].line[0], "      ");
    strcpy(array[10].line[1], "      ");
    strcpy(array[10].line[2], "  ##  ");
    strcpy(array[10].line[3], "  ##  ");
    strcpy(array[10].line[4], "      ");
    strcpy(array[10].line[5], "  ##  ");
    strcpy(array[10].line[6], "  ##  ");
    strcpy(array[10].line[7], "      ");
    strcpy(array[10].line[8], "      ");
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
