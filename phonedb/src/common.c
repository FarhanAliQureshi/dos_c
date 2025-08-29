#include <stdio.h>
#include <graph.h>
#include <string.h>
#include "common.h"
#include "kbinput.h"

void press_any_key_to_continue()
{
    printf("\nPress any key to continue...");
    fflush(stdout);
    wait_for_any_key();
}

void clearscreen()
{
    _clearscreen(_GWINDOW);
}

void turn_off_cursor()
{
    _displaycursor(_GCURSOROFF);
    _settextcursor(NO_CURSOR);
}

void turn_on_cursor()
{
    _displaycursor(_GCURSORON);
    _settextcursor(NORMAL_CURSOR);    
}

enum BOOL ask_yesno_question(char *question)
{
    char keys[5];
    int choice;

    printf(question);
    fflush(stdout);
    strcpy(keys, "YyNn");
    choice = wait_for_key_from_list(keys);
    if (choice == 'Y' || choice == 'y')
        return TRUE;
    else
        return FALSE;
}
