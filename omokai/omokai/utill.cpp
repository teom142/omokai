#include "omok.h"
#include "omokai.h"
int main_board[MAX_SIZE + 1][MAX_SIZE]; //메인 대국판

int con_dol(int dire, int x, int y, int num, int open)
{
	int dol = main_board[x][y];
	if (dol == 0)
		return 0;
	if (dire == 1)
	{
		if (is_safe(y + num - 1))
			return 0;
		for (int i = y + 1; i < y + num; i++)
			if (dol != main_board[x][i])
				return 0;
		if (open)
		{
			if (is_safe(y - 1) && is_safe(y + num))
				return 0;
			if (main_board[x][y - 1] == 0 && main_board[x][y + num] == 0)
				return 1;
			if (main_board[x][y - 1] == 0 || main_board[x][y + num] == 0)
				return 2;
			return 0;
		}
		return 1;
	}
	if (dire == 2)
	{
		if (is_safe(x + num - 1))
			return 0;
		for (int i = x + 1; i < x + num; i++)
			if (dol != main_board[i][y])
				return 0;
		if (open)
		{
			if (is_safe(x - 1) && is_safe(x + num))
				return 0;
			if (main_board[x - 1][y] == 0 && main_board[x + num][y] == 0)
				return 1;
			if (main_board[x - 1][y] == 0 || main_board[x + num][y] == 0)
				return 2;
			return 0;
		}
		return 1;
	}
	if (dire == 3)
	{
		if (is_safe(y + num - 1) && is_safe(x + num - 1))
			return 0;
		for (int i = 1; i < num; i++)
			if (dol != main_board[x + i][y + i])
				return 0;
		if (open)
		{
			if (is_safe(y - 1) && is_safe(y + num) && is_safe(x - 1) && is_safe(x + num))
				return 0;
			if (main_board[x - 1][y - 1] == 0 && main_board[x + num][y + num] == 0)
				return 1;
			if (main_board[x - 1][y - 1] == 0 || main_board[x + num][y + num] == 0)
				return 2;
			return 0;
		}
		return 1;
	}
	if (dire == 4)
	{
		if (is_safe(y - num + 1) && is_safe(x + num - 1))
			return 0;
		for (int i = 1; i < num; i++)
			if (dol != main_board[x + i][y - i])
				return 0;
		return 1;
	}
	return 0;
}

int is_safe(int n)
{
	if (n < 0 || n >= MAX_SIZE)
		return 1;
	return 0;
}