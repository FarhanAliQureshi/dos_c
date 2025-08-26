#ifndef GAMEIO_H
#define GAMEIO_H

#include "kbinput.h"

enum GAME_KEYS
{
    KEY_UNKNOWN,
    KEY_ESCAPE,
    KEY_ENTER,
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT
};

void play_error_beep();
enum GAME_KEYS wait_for_user_input();

#endif
