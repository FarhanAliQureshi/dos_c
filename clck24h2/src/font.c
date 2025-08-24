#include <string.h>
#include <malloc.h>
#include "font.h"

void init_characters(Font array)
{
    // 0
    strcpy(array[0].line[0], "€ﬂﬂﬂﬂﬂﬂ€");
    strcpy(array[0].line[1], "€      €");
    strcpy(array[0].line[2], "€      €");
    strcpy(array[0].line[3], "€      €");
    strcpy(array[0].line[4], "€      €");
    strcpy(array[0].line[5], "€      €");
    strcpy(array[0].line[6], "€      €");
    strcpy(array[0].line[7], "€      €");
    strcpy(array[0].line[8], "ﬂﬂﬂﬂﬂﬂﬂﬂ");

    // 1
    strcpy(array[1].line[0], "       €");
    strcpy(array[1].line[1], "       €");
    strcpy(array[1].line[2], "       €");
    strcpy(array[1].line[3], "       €");
    strcpy(array[1].line[4], "       €");
    strcpy(array[1].line[5], "       €");
    strcpy(array[1].line[6], "       €");
    strcpy(array[1].line[7], "       €");
    strcpy(array[1].line[8], "       ﬂ");

    // 2
    strcpy(array[2].line[0], "ﬂﬂﬂﬂﬂﬂﬂ€");
    strcpy(array[2].line[1], "       €");
    strcpy(array[2].line[2], "       €");
    strcpy(array[2].line[3], "       €");
    strcpy(array[2].line[4], "€ﬂﬂﬂﬂﬂﬂﬂ");
    strcpy(array[2].line[5], "€       ");
    strcpy(array[2].line[6], "€       ");
    strcpy(array[2].line[7], "€       ");
    strcpy(array[2].line[8], "ﬂﬂﬂﬂﬂﬂﬂﬂ");

    // 3
    strcpy(array[3].line[0], "ﬂﬂﬂﬂﬂﬂﬂ€");
    strcpy(array[3].line[1], "       €");
    strcpy(array[3].line[2], "       €");
    strcpy(array[3].line[3], "       €");
    strcpy(array[3].line[4], "ﬂﬂﬂﬂﬂﬂﬂ€");
    strcpy(array[3].line[5], "       €");
    strcpy(array[3].line[6], "       €");
    strcpy(array[3].line[7], "       €");
    strcpy(array[3].line[8], "ﬂﬂﬂﬂﬂﬂﬂﬂ");
    
    // 4
    strcpy(array[4].line[0], "€      €");
    strcpy(array[4].line[1], "€      €");
    strcpy(array[4].line[2], "€      €");
    strcpy(array[4].line[3], "€      €");
    strcpy(array[4].line[4], "ﬂﬂﬂﬂﬂﬂﬂ€");
    strcpy(array[4].line[5], "       €");
    strcpy(array[4].line[6], "       €");
    strcpy(array[4].line[7], "       €");
    strcpy(array[4].line[8], "       ﬂ");
    
    // 5
    strcpy(array[5].line[0], "€ﬂﬂﬂﬂﬂﬂﬂ");
    strcpy(array[5].line[1], "€       ");
    strcpy(array[5].line[2], "€       ");
    strcpy(array[5].line[3], "€       ");
    strcpy(array[5].line[4], "ﬂﬂﬂﬂﬂﬂﬂ€");
    strcpy(array[5].line[5], "       €");
    strcpy(array[5].line[6], "       €");
    strcpy(array[5].line[7], "       €");
    strcpy(array[5].line[8], "ﬂﬂﬂﬂﬂﬂﬂﬂ");
    
    // 6
    strcpy(array[6].line[0], "€ﬂﬂﬂﬂﬂﬂﬂ");
    strcpy(array[6].line[1], "€       ");
    strcpy(array[6].line[2], "€       ");
    strcpy(array[6].line[3], "€       ");
    strcpy(array[6].line[4], "€ﬂﬂﬂﬂﬂﬂ€");
    strcpy(array[6].line[5], "€      €");
    strcpy(array[6].line[6], "€      €");
    strcpy(array[6].line[7], "€      €");
    strcpy(array[6].line[8], "ﬂﬂﬂﬂﬂﬂﬂﬂ");
    
    // 7
    strcpy(array[7].line[0], "ﬂﬂﬂﬂﬂﬂﬂ€");
    strcpy(array[7].line[1], "       €");
    strcpy(array[7].line[2], "       €");
    strcpy(array[7].line[3], "       €");
    strcpy(array[7].line[4], "       €");
    strcpy(array[7].line[5], "       €");
    strcpy(array[7].line[6], "       €");
    strcpy(array[7].line[7], "       €");
    strcpy(array[7].line[8], "       ﬂ");

    // 8
    strcpy(array[8].line[0], "€ﬂﬂﬂﬂﬂﬂ€");
    strcpy(array[8].line[1], "€      €");
    strcpy(array[8].line[2], "€      €");
    strcpy(array[8].line[3], "€      €");
    strcpy(array[8].line[4], "€ﬂﬂﬂﬂﬂﬂ€");
    strcpy(array[8].line[5], "€      €");
    strcpy(array[8].line[6], "€      €");
    strcpy(array[8].line[7], "€      €");
    strcpy(array[8].line[8], "ﬂﬂﬂﬂﬂﬂﬂﬂ");

    // 9
    strcpy(array[9].line[0], "€ﬂﬂﬂﬂﬂﬂ€");
    strcpy(array[9].line[1], "€      €");
    strcpy(array[9].line[2], "€      €");
    strcpy(array[9].line[3], "€      €");
    strcpy(array[9].line[4], "ﬂﬂﬂﬂﬂﬂﬂ€");
    strcpy(array[9].line[5], "       €");
    strcpy(array[9].line[6], "       €");
    strcpy(array[9].line[7], "       €");
    strcpy(array[9].line[8], "       ﬂ");

    // :
    // strcpy(array[10].line[0], "      ");
    // strcpy(array[10].line[1], "      ");
    // strcpy(array[10].line[2], "  €€  ");
    // strcpy(array[10].line[3], "  ﬂﬂ  ");
    // strcpy(array[10].line[4], "      ");
    // strcpy(array[10].line[5], "  ‹‹  ");
    // strcpy(array[10].line[6], "  €€  ");
    // strcpy(array[10].line[7], "      ");
    // strcpy(array[10].line[8], "      ");

    // :
    strcpy(array[10].line[0], "      ");
    strcpy(array[10].line[1], "      ");
    strcpy(array[10].line[2], "  ‹‹  ");
    strcpy(array[10].line[3], "  ﬂﬂ  ");
    strcpy(array[10].line[4], "      ");
    strcpy(array[10].line[5], "  ‹‹  ");
    strcpy(array[10].line[6], "  ﬂﬂ  ");
    strcpy(array[10].line[7], "      ");
    strcpy(array[10].line[8], "      ");

    // BLANK
    strcpy(array[11].line[0], "      ");
    strcpy(array[11].line[1], "      ");
    strcpy(array[11].line[2], "      ");
    strcpy(array[11].line[3], "      ");
    strcpy(array[11].line[4], "      ");
    strcpy(array[11].line[5], "      ");
    strcpy(array[11].line[6], "      ");
    strcpy(array[11].line[7], "      ");
    strcpy(array[11].line[8], "      ");
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
