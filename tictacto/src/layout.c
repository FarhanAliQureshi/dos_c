#include <graph.h>
#include <string.h>
#include <stdio.h>
#include "layout.h"
#include "pritxt.h"
#include "kbinput.h"

#define LINE_WIDTH                  80
#define TITLE                       "T I C    T A C    T O E"
#define PROGRAMMER                  "Program by Farhan Ali Qureshi"
#define KEY_PLAY_HUMAN              '1'
#define KEY_PLAY_COMPUTER_NOVICE    '2'
#define KEY_PLAY_COMPUTER_EXPERT    '3'
#define KEY_EXIT                    '0'


void base_layout()
{
    char line_eraser[LINE_WIDTH + 1];
    memset(line_eraser, ' ', sizeof(line_eraser) / sizeof(line_eraser[0]));
    line_eraser[LINE_WIDTH] = 0x00;

    _clearscreen(_GCLEARSCREEN);
    // Print title.
    pricolor(1, 1, 7, 3, line_eraser);
    pricolor(1, 0, 14, 3, TITLE);
    // Print status bar.
    pricolor(25, 1, 1, 7, line_eraser);
    pricolor(25, 0, 1, 7, PROGRAMMER);

    // Set working screen.
    _settextwindow(2, 1, 24, 80);
    _setbkcolor(1);
    _clearscreen(_GWINDOW);
}

enum MAIN_MENU display_mainmenu()
{
    char keys[81];
    int ch;

    // Display Main Menu.
    _clearscreen(_GWINDOW);
    pricolor(8, 0, 15, 1, "Main Menu");
    pricolor(11, 28, 15, 1, "(1) Player vs Player");
    pricolor(12, 28, 15, 1, "(2) Player vs Novice Computer");
    pricolor(13, 28, 15, 1, "(3) Player vs Expert Computer");
    pricolor(14, 28, 15, 1, "(0) Exit");
    // Highlight keys for menu selection.
    pricolor(11, 29, 13, 1, "1");
    pricolor(12, 29, 13, 1, "2");
    pricolor(13, 29, 13, 1, "3");
    pricolor(14, 29, 13, 1, "0");

    sprintf(keys, "%c%c%c%c", 
        KEY_EXIT, 
        KEY_PLAY_HUMAN, 
        KEY_PLAY_COMPUTER_NOVICE,
        KEY_PLAY_COMPUTER_EXPERT
    );
    ch = wait_for_key_from_list(keys);
    switch (ch)
    {
        case KEY_PLAY_HUMAN:
            return MAIN_MENU_HUMAN_GAME;
            break;
        case KEY_PLAY_COMPUTER_NOVICE:
            return MAIN_MENU_COMPUTER_NOVICE_GAME;
            break;
        case KEY_PLAY_COMPUTER_EXPERT:
            return MAIN_MENU_COMPUTER_EXPERT_GAME;
            break;
        case KEY_EXIT:
            return MAIN_MENU_EXIT;
            break;
    }

    return MAIN_MENU_EXIT;
}