#pragma once
#include "omok.h"

class omok_board
{
	int aix , aiy;
public:
	int main_board[MAX_SIZE + 1][MAX_SIZE];

	omok_board();
	int get_board_dol(int x, int y);
	int set_board(int x, int y, int val);		//main_board[x][y]�� val�� �����Ѵ�
	void init_board();							//main_board �ʱ�ȭ
	int is_win();								//����ڰ� �̱�� 1�� ai�� �̱�� -1��	
	void prt_victory();
	void prt_lose();
	void prt_board();
	int user_input(int* x, int* y, int val);
	void prt_board_easy();

};