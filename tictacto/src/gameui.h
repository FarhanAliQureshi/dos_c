#ifndef GAMEUI_H
#define GAMEUI_H

void display_base_board();
void display_game_title(char *player1, char *player2);
void display_instructions(int row, int col, char *player);
void show_player1_instructions(char *player);
void show_player2_instructions(char *player);
void hide_instructions(int row, int col);
void hide_player1_instructions();
void hide_player2_instructions();
void show_box_outline(int board_row, int board_col);
void hide_box_outline(int board_row, int board_col);
void place_mark(int board_row, int board_col, char *mark);
void display_result_won(int board_row, int board_col, char *player_name);
void display_result_draw_game(int board_row, int board_col);

#endif