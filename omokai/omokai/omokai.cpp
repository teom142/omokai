#include "omokai.h"

omokai::omokai()
{

}

void omokai::set_ai_xy(omok_board& bo)
{
	ai_x = 0;
	ai_y = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (bo.main_board[i][j] != 0)
				val_board[i][j] = 0;
			if (val_board[ai_x][ai_y] < val_board[i][j])
			{
				ai_x = i;
				ai_y = j;
			}
		}
	}
	val_board[ai_x][ai_y] = 0;
}

void omokai::prt_val_voard()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
			cout << setw(4) << val_board[i][j];
		cout << endl;
	}
}

void omokai::alloc_val(int x, int y, int val)
{
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (i != 0 || j != 0)
				if (!is_safe(x + i) || !is_safe(y + i))
					val_board[x + i][y + j] = val;
}

void omokai::special_val(omok_board& bo)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			close_2(i, j, bo);
			open_2(i, j, bo);
			close_3(i, j, bo);
			open_3(i, j, bo);
		}
	}
	set_ai_xy(bo);
}

int omokai::close_2(int x, int y, omok_board& bo)
{
	if (bo.main_board[x][y] != 1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2))
		return 0;
	if (con_dol(1, x, y, 2, bo.main_board))//bo.main_board[x][y + 1] == 1)
	{
		if (is_safe_close(x, y - 1, bo) != is_safe_close(x, y + 2, bo))
		{
			if (!is_safe_close(x, y - 1, bo) && val_board[x][y - 1] < 30)
				val_board[x][y - 1] = 30;
			else if (!is_safe_close(x, y + 2, bo) && val_board[x][y + 2] < 30)
				val_board[x][y + 2] = 30;
		}
	}
	for (int i = -1; i <= 1; i++)
		if (con_dol(3 + i, x, y, 2, bo.main_board))//bo.main_board[x + 1][y - i] == 1)
			if (is_safe_close(x - 1, y + i, bo) != is_safe_close(x + 2, y + i * -2, bo))
			{
				if (!is_safe_close(x - 1, y + i, bo) && val_board[x - 1][y + i] < 30)
					val_board[x - 1][y + i] = 30;
				else if (!is_safe_close(x + 2, y + i * -2, bo) && val_board[x + 2][y + i * -2] < 30)
					val_board[x + 2][y + i * -2] = 30;
			}
	return 1;
}

int omokai::open_2(int x, int y, omok_board& bo)
{
	if (bo.main_board[x][y] != 1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2))
		return 0;
	if (con_dol(1, x, y, 2, bo.main_board))//bo.main_board[x][y + 1] == 1)
	{
		if (is_safe_close(x, y - 1, bo) == 0 && is_safe_close(x, y + 2, bo) == 0
				&& val_board[x][y - 1] < 40 && val_board[x][y + 2] < 40)
		{
			val_board[x][y - 1] = 40;
			val_board[x][y + 2] = 40;
		}
	}
	for (int i = -1; i <= 1; i++)
	{
		if (con_dol(3 + i, x, y, 2, bo.main_board))//bo.main_board[x + 1][y - i] == 1)
		{
			if (is_safe_close(x - 1, y + i, bo) == 0 && is_safe_close(x + 2, y + i * -2, bo) == 0
					&& val_board[x - 1][y + i] < 40 && val_board[x + 2][y + i * -2] < 40)
			{
				val_board[x - 1][y + i] = 40;
				val_board[x + 2][y + i * -2] = 40;
			}
		}
	}
	return 1;
}

int omokai::close_3(int x, int y, omok_board& bo)
{
	if (bo.main_board[x][y] != 1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2) && is_safe(x + 3) && is_safe(y + 3))
		return 0;
	if (con_dol(1, x, y, 3, bo.main_board))//bo.main_board[x][y + 1] == 1 && bo.main_board[x][y + 2] == 1)
	{
		if (is_safe_close(x, y - 1, bo) != is_safe_close(x, y + 3, bo) )
		{
			if (!is_safe_close(x, y - 1, bo) && val_board[x][y - 1] < 60)
				val_board[x][y - 1] = 60;
			else if (!is_safe_close(x, y + 3, bo) && val_board[x][y + 3] < 60)
				val_board[x][y + 3] = 60;
		}
	}
	for (int i = -1; i <= 1; i++)
		if (con_dol(i + 3, x, y, 3, bo.main_board))//bo.main_board[x + 1][y + i] == 1 && bo.main_board[x + 2][y + i * -2] == 1)
			if (is_safe_close(x - 1, y + i, bo) != is_safe_close(x + 3, y + i * -3, bo))
			{
				if (!is_safe_close(x - 1, y + i, bo) && val_board[x - 1][y + i] < 60)
					val_board[x - 1][y + i] = 60;
				else if (!is_safe_close(x + 3, y + i * -3, bo) && val_board[x + 3][y + i * -3] < 60)
					val_board[x + 3][y + (i * -3)] = 60;
			}
	return 1;
}

int omokai::open_3(int x, int y, omok_board& bo)
{
	if (bo.main_board[x][y] != 1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2) && is_safe(x + 3) && is_safe(y + 3))
		return 0;
	if (con_dol(1, x, y, 3, bo.main_board))//bo.main_board[x][y + 1] == 1 && bo.main_board[x][y + 2] == 1)
	{
		if (is_safe_close(x, y - 1, bo) == 0 && is_safe_close(x, y + 3, bo) == 0
			&& val_board[x][y - 1] < 400 && val_board[x][y + 3] < 400)
		{
			val_board[x][y - 1] = 400;
			val_board[x][y + 3] = 400;
		}
	}
	for (int i = -1; i <= 1; i++)
	{
		if (con_dol(i + 3, x, y, 3, bo.main_board))//bo.main_board[x + 1][y - i] == 1)
		{
			if (is_safe_close(x - 1, y + i, bo) == 0 && is_safe_close(x + 3, y + i * -3, bo) == 0
				&& val_board[x - 1][y + i] < 400 && val_board[x + 3][y + i * -3] < 400)
			{
				val_board[x - 1][y + i] = 400;
				val_board[x + 3][y + i * -3] = 400;
			}
		}
	}
	return 1;
}

int omokai::is_safe_close(int x, int y, omok_board& bo)		//�ش� ��ġ�� open�̸� 0��ȯ
{
	if (is_safe(x) && is_safe(y))
		return 1;
	if (bo.main_board[x][y] != 0)
		return 1;
	return 0;
}