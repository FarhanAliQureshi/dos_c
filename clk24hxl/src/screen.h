#ifndef SCREEN_H
#define SCREEN_H

#include <graph.h>

enum CURSOR_SHAPE 
{
    NORMAL_CURSOR = 0x0607,
    BLOCK_CURSOR = 0x0007,
    HALF_CURSOR = 0x0407,
    NO_CURSOR = 0x2000
};

struct screen_attrib
{
    int fore_color;
    long back_color;
    int cursor_shape;
    short cursor_mode;
    int activepage;
    int visiblepage;
    short text_wrap;
    struct rccoord cursor_position;
};
typedef struct screen_attrib Screen;

void init_new_screen(Screen *save_screen, int new_page);
void restore_screen(Screen *screen);

#endif
