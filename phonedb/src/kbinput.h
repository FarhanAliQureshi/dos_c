#ifndef KBINPUT_H
#define KBINPUT_H

struct KEY_BYTES {
    int high;
    int low;
};
typedef struct KEY_BYTES EXTENDED_KEY;

void wait_for_any_key();
int wait_for_key_from_list(char *keys_list);
void wait_for_extended_key(EXTENDED_KEY *key);

#endif
