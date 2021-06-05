#pragma once
#include "omok.h"

class omok_board
{
	int aix, aiy;
public:
	int main_board[MAX_SIZE][MAX_SIZE];

	omok_board();
	int get_board_dol(int x, int y);
	int set_board(int x, int y, int val);		//main_board[x][y]를 val로 설정한다
	void init_board();							//main_board 초기화
	int is_win();								//사용자가 이기면 1을 ai가 이기면 -1을	
	void prt_victory();
	void prt_lose();
	void prt_board();
	int user_input(int* x, int* y, int val);	//유저가 착수하는 기능을 구현한 함수이다.

};