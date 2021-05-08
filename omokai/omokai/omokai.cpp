#include "omokai.h"

omokai::omokai()
{

}

void omokai::set_ai_xy(omok_board& bo)
{
	ai_x = 0;
	ai_y = 0;
	int count = 1;
	srand((unsigned int)time(NULL));
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
				count = 1;
			}
			else if (val_board[ai_x][ai_y] == val_board[i][j])
				count++;

		}
	}
	int n = rand() % count + 1;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (val_board[ai_x][ai_y] == val_board[i][j] && n)
				n--;
			if (!n)
			{
				ai_x = i;
				ai_y = j;
				val_board[ai_x][ai_y] = 0;
				return;
			}
		}
	}
}

void omokai::init_val_board()
{
	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			if (val_board[i][j] != 10)
				val_board[i][j] = 0;
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
				if (!is_safe(x + i) && !is_safe(y + j))
					val_board[x + i][y + j] = val;
}

void omokai::special_val(omok_board& bo)
{
	init_val_board();
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			close_2(i, j, bo, 30);
			open_2(i, j, bo, 40);
			close_3(i, j, bo, 60);
			space_3(i, j, bo, 370);
			open_3(i, j, bo, 300);
			close_4(i, j, bo, 400);
			space_4(i, j, bo, 450);
			if (ad_carry >= 1)
				ai_close_4(i, j, bo, 2000);
			if (ad_carry >= 2)
				ai_open_3(i, j, bo, 380);
			if (ad_carry >= 3)
				ai_space_3(i, j, bo, 350);
			if (ad_carry >= 4)
				ai_close_3(i, j, bo, 330);
			if (ad_carry >= 5)
				ai_open_2(i, j, bo, 170);
			if (ad_carry >= 6)
				ai_space_2(i, j, bo, 150);
		}
	}
}

int omokai::close_2(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != 1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2))
		return 0;
	if (con_dol(1, x, y, 2, bo.main_board))
	{
		if (is_safe_close(x, y - 1, bo) != is_safe_close(x, y + 2, bo))
		{
			if (!is_safe_close(x, y - 1, bo) && val_board[x][y - 1] < val)
				val_board[x][y - 1] = val;
			else if (!is_safe_close(x, y + 2, bo) && val_board[x][y + 2] < val)
				val_board[x][y + 2] = val;
		}
	}
	for (int i = -1; i <= 1; i++)
		if (con_dol(3 + i, x, y, 2, bo.main_board))
			if (is_safe_close(x - 1, y + i, bo) != is_safe_close(x + 2, y + i * -2, bo))
			{
				if (!is_safe_close(x - 1, y + i, bo) && val_board[x - 1][y + i] < val)
					val_board[x - 1][y + i] = val;
				else if (!is_safe_close(x + 2, y + i * -2, bo) && val_board[x + 2][y + i * -2] < val)
					val_board[x + 2][y + i * -2] = val;
			}
	return 1;
}

int omokai::open_2(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != 1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2))
		return 0;
	if (con_dol(1, x, y, 2, bo.main_board))
	{
		if (is_safe_close(x, y - 1, bo) == 0 && is_safe_close(x, y + 2, bo) == 0
				&& val_board[x][y - 1] < val && val_board[x][y + 2] < val)
		{
			val_board[x][y - 1] = val;
			val_board[x][y + 2] = val;
		}
	}
	for (int i = -1; i <= 1; i++)
	{
		if (con_dol(3 + i, x, y, 2, bo.main_board))
		{
			if (is_safe_close(x - 1, y + i, bo) == 0 && is_safe_close(x + 2, y + i * -2, bo) == 0
					&& val_board[x - 1][y + i] < val && val_board[x + 2][y + i * -2] < val)
			{
				val_board[x - 1][y + i] = val;
				val_board[x + 2][y + i * -2] = val;
			}
		}
	}
	return 1;
}

int omokai::ai_open_2(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != -1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2))
		return 0;
	if (con_dol(1, x, y, 2, bo.main_board))
	{
		if (is_safe_close(x, y - 1, bo) == 0 && is_safe_close(x, y + 2, bo) == 0
			&& val_board[x][y - 1] < val && val_board[x][y + 2] < val)
		{
			val_board[x][y - 1] = val;
			val_board[x][y + 2] = val;
		}
	}
	for (int i = -1; i <= 1; i++)
	{
		if (con_dol(3 + i, x, y, 2, bo.main_board))
		{
			if (is_safe_close(x - 1, y + i, bo) == 0 && is_safe_close(x + 2, y + i * -2, bo) == 0
				&& val_board[x - 1][y + i] < val && val_board[x + 2][y + i * -2] < val)
			{
				val_board[x - 1][y + i] = val;
				val_board[x + 2][y + i * -2] = val;
			}
		}
	}
	return 1;
}

int omokai::close_3(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != 1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2) && is_safe(x + 3) && is_safe(y + 3))
		return 0;
	if (con_dol(1, x, y, 3, bo.main_board))
	{
		if (is_safe_close(x, y - 1, bo) != is_safe_close(x, y + 3, bo) )
		{
			if (!is_safe_close(x, y - 1, bo) && val_board[x][y - 1] < val)
				val_board[x][y - 1] = val;
			else if (!is_safe_close(x, y + 3, bo) && val_board[x][y + 3] < val)
				val_board[x][y + 3] = val;
		}
	}
	for (int i = -1; i <= 1; i++)
		if (con_dol(i + 3, x, y, 3, bo.main_board))
			if (is_safe_close(x - 1, y + i, bo) != is_safe_close(x + 3, y + i * -3, bo))
			{
				if (!is_safe_close(x - 1, y + i, bo) && val_board[x - 1][y + i] < val)
					val_board[x - 1][y + i] = val;
				else if (!is_safe_close(x + 3, y + i * -3, bo) && val_board[x + 3][y + i * -3] < val)
					val_board[x + 3][y + (i * -3)] = val;
			}
	return 1;
}

int omokai::open_3(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != 1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2) && is_safe(x + 3) && is_safe(y + 3))
		return 0;
	if (con_dol(1, x, y, 3, bo.main_board))
	{
		if (is_safe_close(x, y - 1, bo) == 0 && is_safe_close(x, y + 3, bo) == 0
			&& val_board[x][y - 1] < val && val_board[x][y + 3] < val)
		{
			val_board[x][y - 1] = val;
			val_board[x][y + 3] = val;
		}
	}
	for (int i = -1; i <= 1; i++)
	{
		if (con_dol(i + 3, x, y, 3, bo.main_board))
		{
			if (is_safe_close(x - 1, y + i, bo) == 0 &&  val_board[x - 1][y + i] < val)
				val_board[x - 1][y + i] = val;
			if (is_safe_close(x + 3, y + i * -3, bo) == 0 && val_board[x + 3][y + i * -3] < val)
				val_board[x + 3][y + i * -3] = val;
		}
	}
	return 1;
}

int omokai::close_4(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != 1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2) 
			&& is_safe(x + 3) && is_safe(y + 3) && is_safe(x + 4) && is_safe(y + 4))
		return 0;
	if (con_dol(1, x, y, 4, bo.main_board))
	{
		if (is_safe_close(x, y - 1, bo) != is_safe_close(x, y + 4, bo))
		{
			if (!is_safe_close(x, y - 1, bo) && val_board[x][y - 1] < val)
				val_board[x][y - 1] = val;
			else if (!is_safe_close(x, y + 4, bo) && val_board[x][y + 4] < val)
				val_board[x][y + 4] = val;
		}
	}
	for (int i = -1; i <= 1; i++)
		if (con_dol(i + 3, x, y, 4, bo.main_board))
			if (is_safe_close(x - 1, y + i, bo) != is_safe_close(x + 4, y + i * -4, bo))
			{
				if (!is_safe_close(x - 1, y + i, bo) && val_board[x - 1][y + i] < val)
					val_board[x - 1][y + i] = val;
				else if (!is_safe_close(x + 4, y + i * -4, bo) && val_board[x + 4][y + i * -4] < val)
					val_board[x + 4][y + (i * -4)] = val;
			}
	return 1;
}

int omokai::space_3(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != 1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2)
		&& is_safe(x + 3) && is_safe(y + 3) && is_safe(x + 4) && is_safe(y + 4))
		return 0;
	if (con_dol_with_space(1, x, y, 3, bo.main_board)
		&& is_safe_close(x, y - 1, bo) == 0 && is_safe_close(x, y + 3, bo) == 0)
	{
		if (!is_safe_close(x, y + 1, bo) && val_board[x][y + 1] < val)
			val_board[x][y + 1] = val;
		else if (!is_safe_close(x, y + 2, bo) && val_board[x][y + 2] < val)
			val_board[x][y + 2] = val;
	}
	for (int i = -1; i <= 1; i++)
		if (con_dol_with_space(i + 3, x, y, 3, bo.main_board)
			&& is_safe_close(x - 1, y + i, bo) == 0 && is_safe_close(x + 4, y + i * -4, bo) == 0)
		{
			if (!is_safe_close(x + 1, y - i, bo) && val_board[x + 1][y - i] < val)
				val_board[x + 1][y - i] = val;
			else if (!is_safe_close(x + 2, y - i * 2, bo) && val_board[x + 2][y - i * 2] < val)
				val_board[x + 2][y - i * 2] = val;
		}
	return 1;
}

int omokai::space_4(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != 1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2)
		&& is_safe(x + 3) && is_safe(y + 3) && is_safe(x + 4) && is_safe(y + 4))
		return 0;
	if (con_dol_with_space(1, x, y, 4, bo.main_board))
	{
		if (!is_safe_close(x, y + 1, bo) && val_board[x][y + 1] < val)
			val_board[x][y + 1] = val;
		else if (!is_safe_close(x, y + 2, bo) && val_board[x][y + 2] < val)
			val_board[x][y + 2] = val;
		else if (!is_safe_close(x, y + 3, bo) && val_board[x][y + 3] < val)
			val_board[x][y + 3] = val;
	}
	for (int i = -1; i <= 1; i++)
		if (con_dol_with_space(i + 3, x, y, 4, bo.main_board))
		{
			if (!is_safe_close(x + 1, y - i, bo) && val_board[x + 1][y - i] < val)
				val_board[x + 1][y - i] = val;
			else if (!is_safe_close(x + 2, y - i * 2, bo) && val_board[x + 2][y - i * 2] < val)
				val_board[x + 2][y - i * 2] = val;
			else if (!is_safe_close(x + 3, y - i * 3, bo) && val_board[x + 3][y - i * 3] < val)
				val_board[x + 3][y - i * 3] = val;
		}
	return 1;
}

int omokai::ai_space_2(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != -1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2)
		&& is_safe(x + 3) && is_safe(y + 3))
		return 0;
	if (con_dol_with_space(1, x, y, 2, bo.main_board))
	{
		if (!is_safe_close(x, y + 1, bo) && val_board[x][y + 1] < val)
			val_board[x][y + 1] = val;
	}
	for (int i = -1; i <= 1; i++)
		if (con_dol_with_space(i + 3, x, y, 2, bo.main_board))
		{
			if (!is_safe_close(x + 1, y - i, bo) && val_board[x + 1][y - i] < val)
				val_board[x + 1][y - i] = val;
		}
	return 1;
}


int omokai::ai_space_3(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != -1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2)
		&& is_safe(x + 3) && is_safe(y + 3) && is_safe(x + 4) && is_safe(y + 4))
		return 0;
	if (con_dol_with_space(1, x, y, 3, bo.main_board))
	{
		if (!is_safe_close(x, y + 1, bo) && val_board[x][y + 1] < val)
			val_board[x][y + 1] = val;
		else if (!is_safe_close(x, y + 2, bo) && val_board[x][y + 2] < val)
			val_board[x][y + 2] = val;
	}
	for (int i = -1; i <= 1; i++)
		if (con_dol_with_space(i + 3, x, y, 3, bo.main_board))
		{
			if (!is_safe_close(x + 1, y - i, bo) && val_board[x + 1][y - i] < val)
				val_board[x + 1][y - i] = val;
			else if (!is_safe_close(x + 2, y - i * 2, bo) && val_board[x + 2][y - i * 2] < val)
				val_board[x + 2][y - i * 2] = val;
		}
	return 1;
}

int omokai::ai_close_3(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != -1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2) && is_safe(x + 3) && is_safe(y + 3))
		return 0;
	if (con_dol(1, x, y, 3, bo.main_board))
	{
		if (is_safe_close(x, y - 1, bo) != is_safe_close(x, y + 3, bo))
		{
			if (!is_safe_close(x, y - 1, bo) && val_board[x][y - 1] < val)
				val_board[x][y - 1] = val;
			else if (!is_safe_close(x, y + 3, bo) && val_board[x][y + 3] < val)
				val_board[x][y + 3] = val;
		}
	}
	for (int i = -1; i <= 1; i++)
		if (con_dol(i + 3, x, y, 3, bo.main_board))
			if (is_safe_close(x - 1, y + i, bo) != is_safe_close(x + 3, y + i * -3, bo))
			{
				if (!is_safe_close(x - 1, y + i, bo) && val_board[x - 1][y + i] < val)
					val_board[x - 1][y + i] = val;
				else if (!is_safe_close(x + 3, y + i * -3, bo) && val_board[x + 3][y + i * -3] < val)
					val_board[x + 3][y + (i * -3)] = val;
			}
	return 1;
}

int omokai::ai_open_3(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != -1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2) && is_safe(x + 3) && is_safe(y + 3))
		return 0;
	if (con_dol(1, x, y, 3, bo.main_board))
	{
		if (is_safe_close(x, y - 1, bo) == 0 && is_safe_close(x, y + 3, bo) == 0
			&& val_board[x][y - 1] < val && val_board[x][y + 3] < val)
		{
			val_board[x][y - 1] = val;
			val_board[x][y + 3] = val;
		}
	}
	for (int i = -1; i <= 1; i++)
	{
		if (con_dol(i + 3, x, y, 3, bo.main_board))
		{
			if (is_safe_close(x - 1, y + i, bo) == 0 && is_safe_close(x + 3, y + i * -3, bo) == 0
				&& val_board[x - 1][y + i] < val && val_board[x + 3][y + i * -3] < val)
			{
				val_board[x - 1][y + i] = val;
				val_board[x + 3][y + i * -3] = val;
			}
		}
	}
	return 1;
}

int omokai::ai_close_4(int x, int y, omok_board& bo, int val)
{
	if (bo.main_board[x][y] != -1)
		return 0;
	if (is_safe(y + 1) && is_safe(x + 1) && is_safe(x + 2) && is_safe(y + 2)
		&& is_safe(x + 3) && is_safe(y + 3) && is_safe(x + 4) && is_safe(y + 4))
		return 0;
	if (con_dol(1, x, y, 4, bo.main_board))
	{
		if (is_safe_close(x, y - 1, bo) != is_safe_close(x, y + 4, bo))
		{
			if (!is_safe_close(x, y - 1, bo) && val_board[x][y - 1] < val)
				val_board[x][y - 1] = val;
			else if (!is_safe_close(x, y + 4, bo) && val_board[x][y + 4] < val)
				val_board[x][y + 4] = val;
		}
	}
	for (int i = -1; i <= 1; i++)
		if (con_dol(i + 3, x, y, 4, bo.main_board))
			if (is_safe_close(x - 1, y + i, bo) != is_safe_close(x + 3, y + i * -4, bo))
			{
				if (!is_safe_close(x - 1, y + i, bo) && val_board[x - 1][y + i] < val)
					val_board[x - 1][y + i] = val;
				else if (!is_safe_close(x + 4, y + i * -4, bo) && val_board[x + 4][y + i * -4] < val)
					val_board[x + 4][y + (i * -4)] = val;
			}
	return 1;
}

int omokai::is_safe_close(int x, int y, omok_board& bo)		//�ش� ��ġ�� open�̸� 0��ȯ
{
	if (is_safe(x) || is_safe(y))
		return 1;
	if (bo.main_board[x][y] != 0)
		return 1;
	return 0;
}