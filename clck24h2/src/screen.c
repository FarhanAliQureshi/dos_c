#include "screen.h"

void init_new_screen(Screen *save_screen, int new_page)
{
    save_screen->fore_color = _settextcolor(7);
    save_screen->back_color = _setbkcolor(0);
    save_screen->cursor_position = _gettextposition();
    save_screen->cursor_shape = _gettextcursor();
    _settextcursor(NO_CURSOR);
    save_screen->cursor_mode = _displaycursor(_GCURSOROFF);
    save_screen->text_wrap = _wrapon(_GWRAPOFF);
    save_screen->activepage = _setactivepage(new_page);
    save_screen->visiblepage = _setvisualpage(new_page);
    _clearscreen(_GCLEARSCREEN);
}

void restore_screen(Screen *screen)
{
    _setactivepage(screen->activepage);
    _setvisualpage(screen->visiblepage);
    _wrapon(screen->text_wrap);
    _settextcolor(screen->fore_color);
    _setbkcolor(screen->back_color);
    _displaycursor(screen->cursor_mode);
    _settextcursor(screen->cursor_shape);
    _settextposition(screen->cursor_position.row, screen->cursor_position.col); 
}