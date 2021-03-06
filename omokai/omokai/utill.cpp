/*utill.cpp*/
#include "omok.h"
#include "omokai.h"
//int main_board[MAX_SIZE + 1][MAX_SIZE]; //메인 대국판

int con_dol(int dire, int x, int y, int num, int main_board[MAX_SIZE + 1][MAX_SIZE])
{
	int dol = main_board[x][y];
	if (dol == 0)
		return 0;
	if (dire == 1)		//가로
	{
		if (is_safe(y + num - 1))		//index를 벗어나면 바로 0을 return 한다.
			return 0;
		for (int i = y + 1; i < y + num; i++)
			if (dol != main_board[x][i])
				return 0;
		return 1;
	}
	if (dire == 2)		//우하향
	{
		if (is_safe(y + num - 1) && is_safe(x + num - 1))
			return 0;
		for (int i = 1; i < num; i++)
			if (dol != main_board[x + i][y + i])
				return 0;
		return 1;
	}
	if (dire == 3)		//세로
	{
		if (is_safe(x + num - 1))
			return 0;
		for (int i = x + 1; i < x + num; i++)
			if (dol != main_board[i][y])
				return 0;
		return 1;
	}
	if (dire == 4)		//좌하향
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

int con_dol_with_space(int dire, int x, int y, int num, int main_board[MAX_SIZE + 1][MAX_SIZE])
{
	int dol = main_board[x][y];
	int count = 0;
	if (dol == 0)
		return 0;
	if (dire == 1)		//가로
	{
		if (is_safe(y + num - 1))
			return 0;
		for (int i = y + 1; i < y + num + 1; i++)
			if (dol == main_board[x][i])
				count++;
		if (count == num - 1)		//조사하려고 한 돌의 수와 일치해야 1즉 참을 반환한다.
			return 1;
		else
			return 0;
	}
	if (dire == 2)		//우하향
	{
		if (is_safe(y + num - 1) && is_safe(x + num - 1))
			return 0;
		for (int i = 1; i < num + 1; i++)
			if (dol == main_board[x + i][y + i])
				count++;
		if (count == num - 1)
			return 1;
		else
			return 0;
	}
	if (dire == 3)		//세로
	{
		if (is_safe(x + num - 1))
			return 0;
		for (int i = x + 1; i < x + num + 1; i++)
			if (dol == main_board[i][y])
				count++;
		if (count == num - 1)
			return 1;
		else
			return 0;
	}
	if (dire == 4)		//좌하향
	{
		if (is_safe(y - num + 1) && is_safe(x + num - 1))
			return 0;
		for (int i = 1; i < num + 1; i++)
			if (dol == main_board[x + i][y - i])
				count++;
		if (count == num - 1)
			return 1;
		else
			return 0;
	}
	return 0;
}

int is_safe(int n)
{
	if (n < 0 || n >= MAX_SIZE)
		return 1;
	return 0;
}