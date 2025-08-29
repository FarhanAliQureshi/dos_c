#include <string.h>
#include <conio.h>
#include "common.h"
#include "kbinput.h"

void wait_for_any_key()
{
    EXTENDED_KEY key;
    wait_for_extended_key(&key);
}

int wait_for_key_from_list(char *keys_list)
{
    int i, count, ch;

    count = strlen(keys_list);
    while (kbhit()) getch();
    while (TRUE)
    {
        if (kbhit())
        {
            ch = getch();
            if (ch == 0)
            {
                getch();
            }
            else
            {
                for (i = 0; i < count; i++)
                {
                    if (keys_list[i] == ch) return ch;
                }
            }
        }
    }
}

void wait_for_extended_key(EXTENDED_KEY *key)
{
    while (kbhit()) getch();
    while (!kbhit()) {}
    key->high = getch();
    if (key->high == 0)
        key->low = getch();
    else
        key->low = 0;
}
