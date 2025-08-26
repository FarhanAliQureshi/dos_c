#include <graph.h>
#include <stdio.h>
#include <string.h>
#include "pritxt.h"
#include "gameui.h"

#define BOARD_SCREEN_ROW    7
#define BOARD_SCREEN_COL    28
#define GAME_TITLE_ROW      3
#define PLAYER_HELP_ROW     7
#define PLAYER1_HELP_COL    3
#define PLAYER2_HELP_COL    61

void display_base_board()
{
    int index;

    _clearscreen(_GWINDOW);
    index = BOARD_SCREEN_ROW;
    pricolor(index++, BOARD_SCREEN_COL, 14, 1, "       ³       ³       ");
    pricolor(index++, BOARD_SCREEN_COL, 14, 1, "       ³       ³       ");
    pricolor(index++, BOARD_SCREEN_COL, 14, 1, "       ³       ³       ");
    pricolor(index++, BOARD_SCREEN_COL, 14, 1, "ÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄ");
    pricolor(index++, BOARD_SCREEN_COL, 14, 1, "       ³       ³       ");
    pricolor(index++, BOARD_SCREEN_COL, 14, 1, "       ³       ³       ");
    pricolor(index++, BOARD_SCREEN_COL, 14, 1, "       ³       ³       ");
    pricolor(index++, BOARD_SCREEN_COL, 14, 1, "ÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄ");
    pricolor(index++, BOARD_SCREEN_COL, 14, 1, "       ³       ³       ");
    pricolor(index++, BOARD_SCREEN_COL, 14, 1, "       ³       ³       ");
    pricolor(index++, BOARD_SCREEN_COL, 14, 1, "       ³       ³       ");
}

void display_game_title(char *player1, char *player2)
{
    char player_info[81];

    sprintf(player_info, "%s vs %s", player1, player2);
    pricolor(GAME_TITLE_ROW, 0, 15, 1, player_info);
}

void display_instructions(int row, int col, char *player)
{
    char buffer[81];
    int index;

    index = row;
    sprintf(buffer, "%s's Turn", player);

    pricolor(index, col, 7, 1, buffer);
    index += 2;
    sprintf(buffer, "%c = Up", 0x18);       pricolor(index++, col, 7, 1, buffer);
    sprintf(buffer, "%c = Down", 0x19);     pricolor(index++, col, 7, 1, buffer);
    sprintf(buffer, "%c = Left", 0x1B);     pricolor(index++, col, 7, 1, buffer);
    sprintf(buffer, "%c = Right", 0x1A);    pricolor(index++, col, 7, 1, buffer);
    strcpy(buffer, "Enter = Place Mark");   pricolor(index++, col, 7, 1, buffer);
    strcpy(buffer, "Esc = Exit to Menu");   pricolor(index++, col, 7, 1, buffer);
}

void hide_instructions(int row, int col)
{
    int index;
    char buffer[21];

    memset(buffer, ' ', sizeof(buffer) / sizeof(buffer[0]));
    buffer[20] = 0x00;

    for (index = row; index < row + 8; index++)
        pri(index, col, buffer);
}

void show_player1_instructions(char *player)
{
    display_instructions(PLAYER_HELP_ROW, PLAYER1_HELP_COL, player);
}

void show_player2_instructions(char *player)
{
    display_instructions(PLAYER_HELP_ROW, PLAYER2_HELP_COL, player);
}

void hide_player1_instructions()
{
    hide_instructions(PLAYER_HELP_ROW, PLAYER1_HELP_COL);
}

void hide_player2_instructions()
{
    hide_instructions(PLAYER_HELP_ROW, PLAYER2_HELP_COL);
}

void show_box_outline(int board_row, int board_col)
{
    int row, col;

    row = BOARD_SCREEN_ROW + (board_row * 4);
    col = BOARD_SCREEN_COL + 1 + (board_col * 8);
    pricolor(row++, col + 0, 13, 1, "ÚÄÄÄ¿");
    pricolor(row  , col + 0, 13, 1, "³");
    pricolor(row++, col + 4, 13, 1, "³");
    pricolor(row++, col + 0, 13, 1, "ÀÄÄÄÙ");    
}

void hide_box_outline(int board_row, int board_col)
{
    int row, col;

    row = BOARD_SCREEN_ROW + (board_row * 4);
    col = BOARD_SCREEN_COL + 1 + (board_col * 8);
    pricolor(row++, col + 0, 13, 1, "     ");
    pricolor(row  , col + 0, 13, 1, " ");
    pricolor(row++, col + 4, 13, 1, " ");
    pricolor(row++, col + 0, 13, 1, "     ");    
}

void place_mark(int board_row, int board_col, char *mark)
{
    int row, col;

    row = BOARD_SCREEN_ROW + 1 + (board_row * 4);
    col = BOARD_SCREEN_COL + 3 + (board_col * 8);

    pricolor(row, col, 15, 1, mark);
}

void display_result_won(int board_row, int board_col, char *player_name)
{
    char buffer[81];
    sprintf(buffer, "%s WON!", player_name);

    hide_box_outline(board_row, board_col);
    hide_player1_instructions();
    hide_player2_instructions();
    pricolor(20, 0, 13, 1, buffer);
    pricolor(22, 0, 7, 1, "Press any key to back to menu.");
}

void display_result_draw_game(int board_row, int board_col)
{
    hide_box_outline(board_row, board_col);
    hide_player1_instructions();
    hide_player2_instructions();
    pricolor(20, 0, 13, 1, "Draw Game");
    pricolor(22, 0, 7, 1, "Press any key to back to menu.");
}
