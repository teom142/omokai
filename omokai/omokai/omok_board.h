#pragma once
#include "omok.h"

class omok_board
{
	int aix , aiy;
public:
	int main_board[MAX_SIZE + 1][MAX_SIZE];

	omok_board();
	int get_board_dol(int x, int y);
	int set_board(int x, int y, int val);		//main_board[x][y]를 val로 설정한다
	void init_board();							//main_board 초기화
	int is_win();								//사용자가 이기면 1을 ai가 이기면 -1을	
	void prt_victory();
	void prt_lose();
	void prt_board();
	int user_input(int* x, int* y, int val);
	void prt_board_easy();

};