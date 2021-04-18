#pragma once
#include "omok.h"

class omok_board
{
	int main_board[MAX_SIZE + 1][MAX_SIZE];
public:

	int set_board(int x, int y, int val)		//main_board[x][y]를 val로 설정한다
	{
		if (is_safe(y) || main_board[x][y] == -1 || main_board[x][y] == 1)
			return 1;
		if (x < 0 || x > MAX_SIZE)
			return 1;
		main_board[x][y] = val;
		return 0;
	}

	void init_board()
	{
		for (int i = 0; i < MAX_SIZE; i++)
			for (int j = 0; j < MAX_SIZE; j++)
				main_board[i][j] = 0;
	}

	int is_win()								//사용자가 이기면 1을 ai가 이기면 -1을 
	{
		for (int i = 0; i < MAX_SIZE; i++)
			for (int j = 0; j < MAX_SIZE; j++)
				for (int k = 1; k <= 4; k++)
					if (con_dol(k, i, j, 5, 0))
						return main_board[i][j];
		return 0;
	}

	void prt_victory();
	void prt_lose();
	void prt_board();
	void user_input(int* x, int* y, int val);
};