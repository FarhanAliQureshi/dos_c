/*

    PROJECT: TIC TAC TOE
    PROGRAMMER: FARHAN ALI QURESHI
    DESCRIPTION: Human vs Human, and Human vs Computer

    NOTES: 
    * Novice Computer will randomly place marks on board without any calculation.
    * Expert Computer will try to defend against human's winning move,
      and will try build for two marks or three marks (winning move).
    * Expert Computer algorithm is not yet implemented.

*/

#include "common.h"
#include "screen.h"
#include "layout.h"
#include "game.h"

int main(void)
{
    Screen screen;
    enum MAIN_MENU choice;
    enum BOOL keep_running;

    keep_running = TRUE;

    // New screen page.
    init_new_screen(&screen, 1);

    // Initial layout.
    base_layout();

    while (keep_running)
    {
        choice = display_mainmenu();
        switch (choice)
        {
            case MAIN_MENU_HUMAN_GAME:
                play_human_vs_human();
                break;
            case MAIN_MENU_COMPUTER_NOVICE_GAME:
                play_human_vs_computer_novice();
                break;
            case MAIN_MENU_COMPUTER_EXPERT_GAME:
                play_human_vs_computer_expert();
                break;
            case MAIN_MENU_EXIT:
                keep_running = FALSE;
                break;
        }
    }

    // Cleanup.
    restore_screen(&screen);

    return 0;
}
