#include <string.h>
#include "common.h"
#include "game.h"
#include "gameui.h"
#include "gameio.h"
#include "gameai.h"

enum GAME_PLAY_TURN
{
    PLAYER1_TURN,
    PLAYER2_TURN
};

enum GAME_RESULT
{
    GAME_CONTINUE,
    GAME_PLAYER1_WON,
    GAME_PLAYER2_WON,
    GAME_DRAW
};

enum GAME_RESULT game_result(int board[][3]);
void game_play_turn_help(enum GAME_PLAY_TURN turn, char *player1, char *player2);
void move_box_outline(enum GAME_KEYS key, int *board_row, int *board_col);
void play_turn(enum GAME_PLAY_TURN *turn, int board_row, int board_col, int board[][3]);
enum BOOL has_game_ended(enum GAME_RESULT result, int board_row, int board_col, char *player1, char *player2);


void play_human_vs_human()
{
    char player1[81], player2[81];
    enum GAME_KEYS key;
    enum GAME_PLAY_TURN turn;
    enum GAME_RESULT result;
    enum BOOL game_loop;
    int board_row, board_col;
    int board[3][3];    // Value of 0 = no mark. 1 = Player1's mark. 2 = Player2's mark.
    int i, j;

    strcpy(player1, "Player 1");
    strcpy(player2, "Player 2");
    turn = PLAYER1_TURN;
    game_loop = TRUE;
    board_row = 0; board_col = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = 0;            // 0 means there is no mark in that cell.
        }
    }

    display_base_board();
    display_game_title(player1, player2);
    show_box_outline(board_row, board_col);

    while (game_loop)
    {
        game_play_turn_help(turn, player1, player2);
        key = wait_for_user_input();
        move_box_outline(key, &board_row, &board_col);
        
        if (key == KEY_ESCAPE) game_loop = FALSE;
        if (key == KEY_ENTER) {
            if (board[board_row][board_col] == 0) {
                // play_turn() will change turn for other player.
                play_turn(&turn, board_row, board_col, board);
                result = game_result(board);
                if (has_game_ended(result, board_row, board_col, player1, player2) == TRUE) {
                    wait_for_any_key();
                    game_loop = FALSE;
                }
            } else {
                play_error_beep();
            }
        }
    }
}

void play_human_vs_computer_novice()
{
    char player1[81], player2[81], player2_title[81];
    enum GAME_KEYS key;
    enum GAME_PLAY_TURN turn;
    enum GAME_RESULT result;
    int board_row, board_col;
    int board[3][3];    // Value of 0 = no mark. 1 = Player1's mark. 2 = Player2's mark.
    int i, j;

    strcpy(player1, "Player");
    strcpy(player2, "Computer");
    strcpy(player2_title, "Novice Computer");
    turn = PLAYER1_TURN;
    board_row = 0; board_col = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = 0;            // 0 means there is no mark in that cell.
        }
    }

    display_base_board();
    display_game_title(player1, player2_title);
    game_play_turn_help(turn, player1, player2);
    show_box_outline(board_row, board_col);

    while (TRUE)
    {
        key = wait_for_user_input();
        move_box_outline(key, &board_row, &board_col);
        
        if (key == KEY_ESCAPE) break;
        if (key == KEY_ENTER) {
            if (board[board_row][board_col] == 0) {
                // Human player's turn.
                // play_turn() will change turn for other player, we'll fix it below.
                play_turn(&turn, board_row, board_col, board);
                result = game_result(board);
                if (has_game_ended(result, board_row, board_col, player1, player2) == TRUE) {
                    wait_for_any_key();
                    break;
                }
                // Computer's turn.
                play_turn_computer_novice(board);       // Endless loop if board is full
                result = game_result(board);
                if (has_game_ended(result, board_row, board_col, player1, player2) == TRUE) {
                    wait_for_any_key();
                    break;
                }
                // After computer's turn, change to human's turn.
                turn = PLAYER1_TURN;
            } else {
                play_error_beep();
            }
        }
    }
}

void play_human_vs_computer_expert()
{
    char player1[81], player2[81], player2_title[81];
    enum GAME_KEYS key;
    enum GAME_PLAY_TURN turn;
    enum GAME_RESULT result;
    int board_row, board_col;
    int board[3][3];    // Value of 0 = no mark. 1 = Player1's mark. 2 = Player2's mark.
    int i, j;

    strcpy(player1, "Player");
    strcpy(player2, "Computer");
    strcpy(player2_title, "Expert Computer");
    turn = PLAYER1_TURN;
    board_row = 0; board_col = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = 0;            // 0 means there is no mark in that cell.
        }
    }

    display_base_board();
    display_game_title(player1, player2_title);
    game_play_turn_help(turn, player1, player2);
    show_box_outline(board_row, board_col);

    while (TRUE)
    {
        key = wait_for_user_input();
        move_box_outline(key, &board_row, &board_col);
        
        if (key == KEY_ESCAPE) break;
        if (key == KEY_ENTER) {
            if (board[board_row][board_col] == 0) {
                // Human player's turn.
                // play_turn() will change turn for other player, we'll fix it below.
                play_turn(&turn, board_row, board_col, board);
                result = game_result(board);
                if (has_game_ended(result, board_row, board_col, player1, player2) == TRUE) {
                    wait_for_any_key();
                    break;
                }
                // Computer's turn.
                play_turn_computer_expert(board);
                result = game_result(board);
                if (has_game_ended(result, board_row, board_col, player1, player2) == TRUE) {
                    wait_for_any_key();
                    break;
                }
                // After computer's turn, change to human's turn.
                turn = PLAYER1_TURN;
            } else {
                play_error_beep();
            }
        }
    }
}

enum GAME_RESULT game_result(int board[][3])
{
    int row, col, player;

    for (player = 1; player <= 2; player++) {
        // Check rows.
        for (row = 0; row < 3; row++)
            if (board[row][0] == player && board[row][1] == player && board[row][2] == player)
                return player == 1 ? GAME_PLAYER1_WON : GAME_PLAYER2_WON;

        // Check columns.
        for (col = 0; col < 3; col++)
            if (board[0][col] == player && board[1][col] == player && board[2][col] == player)
                return player == 1 ? GAME_PLAYER1_WON : GAME_PLAYER2_WON;

        // Check diagonals.
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return player == 1 ? GAME_PLAYER1_WON : GAME_PLAYER2_WON;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return player == 1 ? GAME_PLAYER1_WON : GAME_PLAYER2_WON;        
    }

    // If there is at least one cell left unmarked then game continues.
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (board[row][col] == 0)
                return GAME_CONTINUE;
        }
    }

    // If all cells are marked and no one won then it is a draw game.
    return GAME_DRAW;
}

void game_play_turn_help(enum GAME_PLAY_TURN turn, char *player1, char *player2)
{
    if (turn == PLAYER1_TURN) {
        hide_player2_instructions();
        show_player1_instructions(player1);
    } else {
        hide_player1_instructions();
        show_player2_instructions(player2);
    }
}

void move_box_outline(enum GAME_KEYS key, int *board_row, int *board_col)
{
    if (key == KEY_UP && *board_row > 0) {
        hide_box_outline(*board_row, *board_col);
        *board_row -= 1;
        show_box_outline(*board_row, *board_col);
    }
    if (key == KEY_DOWN && *board_row < 2) {
        hide_box_outline(*board_row, *board_col);
        *board_row += 1;
        show_box_outline(*board_row, *board_col);
    }
    if (key == KEY_LEFT && *board_col > 0) {
        hide_box_outline(*board_row, *board_col);
        *board_col -= 1;
        show_box_outline(*board_row, *board_col);
    }
    if (key == KEY_RIGHT && *board_col < 2) {
        hide_box_outline(*board_row, *board_col);
        *board_col += 1;
        show_box_outline(*board_row, *board_col);
    }
}

void play_turn(enum GAME_PLAY_TURN *turn, int board_row, int board_col, int board[][3])
{
    if (*turn == PLAYER1_TURN) {
        board[board_row][board_col] = 1;
        place_mark(board_row, board_col, "X");
        *turn = PLAYER2_TURN;
    } else {
        board[board_row][board_col] = 2;
        place_mark(board_row, board_col, "O");
        *turn = PLAYER1_TURN;
    }
}

enum BOOL has_game_ended(enum GAME_RESULT result, int board_row, int board_col, char *player1, char *player2)
{
    switch (result)
    {
        case GAME_PLAYER1_WON:
            display_result_won(board_row, board_col, player1);
            return TRUE;
        case GAME_PLAYER2_WON:
            display_result_won(board_row, board_col, player2);
            return TRUE;
        case GAME_DRAW:
            display_result_draw_game(board_row, board_col);
            return TRUE;
    }

    return FALSE;
}

