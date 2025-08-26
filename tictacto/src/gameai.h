#ifndef GAMEAI_H
#define GAMEAI_H

void play_turn_computer_novice(int board[][3]);
enum BOOL computer_expert_winning_move(int player_check1, int player_check2, int player_mark, int board[][3]);
void play_turn_computer_expert(int board[][3]);

#endif
