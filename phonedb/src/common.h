#ifndef COMMON_H
#define COMMON_H

enum CursorShape {
    NORMAL_CURSOR = 0x0607,
    BLOCK_CURSOR = 0x0007,
    HALF_CURSOR = 0x0407,
    NO_CURSOR = 0x2000
};

enum BOOL {FALSE, TRUE};

enum BOOL ask_yesno_question(char *question);
void press_any_key_to_continue();
void clearscreen();
void turn_off_cursor();
void turn_on_cursor();

#endif
