#include <time.h>
#include <stdlib.h>
#include "common.h"
#include "gameai.h"
#include "gameui.h"

void play_turn_computer_novice(int board[][3])
{
    int row, col;

    srand(time(NULL));
    while (TRUE)
    {
        row = rand() % 3;
        col = rand() % 3;
        if (board[row][col] == 0) {
            board[row][col] = 2;
            place_mark(row, col, "O");
            break;
        }
    }
}

void play_turn_computer_expert(int board[][3])
{
    int row, col;
    enum BOOL empty_board;

    // If board is empty then ask Novice to randomly put a mark on board.
    empty_board = TRUE;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (board[row][col] != 0) {
                empty_board = FALSE;
                break;
            }
        }
        if (empty_board == FALSE) break;
    }
    if (empty_board == TRUE) {
        play_turn_computer_novice(board);
        return;
    }

    // If there is a winning move available then play it.
    if (computer_expert_winning_move(2, 2, 2, board) == TRUE) return;

    // Prevent player from winning move.
    if (computer_expert_winning_move(1, 1, 2, board) == TRUE) return;

    // If a row or a column has two empty cells but one cell has 
    // computer's mark then place a second mark in that row or column.
    if (computer_expert_winning_move(2, 0, 2, board) == TRUE) return;
    if (computer_expert_winning_move(0, 2, 2, board) == TRUE) return;    

    // We ran out of tricks, ask Novice to place a mark in a random cell.
    play_turn_computer_novice(board);
}

enum BOOL computer_expert_winning_move(int player_check1, int player_check2, int player_mark, int board[][3])
{
    int row, col;

    // Check rows.
    for (row = 0; row < 3; row++) {
        // Row Pattern XX_
        if (board[row][0] == player_check1 && board[row][1] == player_check2 && board[row][2] == 0) {
            board[row][2] = player_mark;
            place_mark(row, 2, "O");
            return TRUE;
        }
        // Row Pattern _XX
        if (board[row][0] == 0 && board[row][1] == player_check1 && board[row][2] == player_check2) {
            board[row][0] = player_mark;
            place_mark(row, 0, "O");
            return TRUE;
        }
        // Row Pattern X_X
        if (board[row][0] == player_check1 && board[row][1] == 0 && board[row][2] == player_check2) {
            board[row][1] = player_mark;
            place_mark(row, 1, "O");
            return TRUE;
        }
    }

    // Check columns.
    for (col = 0; col < 3; col++) {
        // Column Pattern XX_
        if (board[0][col] == player_check1 && board[1][col] == player_check2 && board[2][col] == 0) {
            board[2][col] = player_mark;
            place_mark(2, col, "O");
            return TRUE;
        }
        // Column Pattern _XX
        if (board[0][col] == 0 && board[1][col] == player_check1 && board[2][col] == player_check2) {
            board[0][col] = player_mark;
            place_mark(0, col, "O");
            return TRUE;
        }
        // Column Pattern X_X
        if (board[0][col] == player_check1 && board[1][col] == 0 && board[2][col] == player_check2) {
            board[1][col] = player_mark;
            place_mark(1, col, "O");
            return TRUE;
        }
    }

    // Check diagonals. Backslash style.
    if (board[0][0] == player_check1 && board[1][1] == player_check2 && board[2][2] == 0) {
        board[2][2] = player_mark;
        place_mark(2, 2, "O");
        return TRUE;
    }
    if (board[0][0] == 0 && board[1][1] == player_check1 && board[2][2] == player_check2) {
        board[0][0] = player_mark;
        place_mark(0, 0, "O");
        return TRUE;
    }
    if (board[0][0] == player_check1 && board[1][1] == 0 && board[2][2] == player_check2) {
        board[1][1] = player_mark;
        place_mark(1, 1, "O");
        return TRUE;
    }
    // Check diagonals. Forward slash style.
    if (board[0][2] == player_check1 && board[1][1] == player_check2 && board[2][0] == 0) {
        board[2][0] = player_mark;
        place_mark(2, 0, "O");
        return TRUE;
    }
    if (board[0][2] == 0 && board[1][1] == player_check1 && board[2][0] == player_check2) {
        board[0][2] = player_mark;
        place_mark(0, 2, "O");
        return TRUE;
    }
    if (board[0][2] == player_check1 && board[1][1] == 0 && board[2][0] == player_check2) {
        board[1][1] = player_mark;
        place_mark(1, 1, "O");
        return TRUE;
    }

    return FALSE;
}
