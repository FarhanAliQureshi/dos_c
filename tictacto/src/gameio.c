#include <dos.h>
#include "gameio.h"

enum GAME_KEYS translate_to_game_key(EXTENDED_KEY *key);

void play_error_beep()
{
    sound(850);
    delay(100);
    nosound();
}

enum GAME_KEYS translate_to_game_key(EXTENDED_KEY *key)
{
    if (key->high == 0x1B && key->low == 0x00) return KEY_ESCAPE;
    if (key->high == 0x0D && key->low == 0x00) return KEY_ENTER;
    if (key->high == 0x00 && key->low == 0x48) return KEY_UP;
    if (key->high == 0x00 && key->low == 0x50) return KEY_DOWN;
    if (key->high == 0x00 && key->low == 0x4B) return KEY_LEFT;
    if (key->high == 0x00 && key->low == 0x4D) return KEY_RIGHT;

    return KEY_UNKNOWN;
}

enum GAME_KEYS wait_for_user_input()
{
    EXTENDED_KEY extended_key;

    wait_for_extended_key(&extended_key);
    return translate_to_game_key(&extended_key);
}
