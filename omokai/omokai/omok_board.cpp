#include "omok_board.h"

int omok_board::get_board_dol(int x, int y)
{
	return main_board[x][y];
}

int omok_board::set_board(int x, int y, int val)
{
	if (is_safe(y) || main_board[x][y] == -1 || main_board[x][y] == 1)
		return 1;
	if (x < 0 || x > MAX_SIZE)
		return 1;
	main_board[x][y] = val;
	return 0;
}

void omok_board::init_board()
{
	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			main_board[i][j] = 0;
}

int omok_board::is_win()
{
	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			for (int k = 1; k <= 4; k++)
				if (con_dol(k, i, j, 5, main_board))
					return main_board[i][j];
	return 0;
}

void omok_board::prt_victory()		//승리시 출력
{
	cout << " __     __  ______   ______   ________   ______   _______   __      __ " << endl;
	cout << "/  |   /  |/      | /      | /        | /      | /       | /  |    /  |" << endl;
	cout << "$$ |   $$ |$$$$$$/ /$$$$$$  |$$$$$$$$/ /$$$$$$  |$$$$$$$  |$$  |  /$$/ " << endl;
	cout << "$$ |   $$ |  $$ |  $$ |  $$/    $$ |   $$ |  $$ |$$ |__$$ | $$  |/$$/  " << endl;
	cout << "$$  | /$$/   $$ |  $$ |         $$ |   $$ |  $$ |$$    $$<   $$  $$/   " << endl;
	cout << " $$  /$$/    $$ |  $$ |   __    $$ |   $$ |  $$ |$$$$$$$  |   $$$$/    " << endl;
	cout << "  $$ $$/    _$$ |_ $$ |__/  |   $$ |   $$ |__$$ |$$ |  $$ |    $$ |    " << endl;
	cout << "   $$$/    / $$   |$$    $$/    $$ |   $$    $$/ $$ |  $$ |    $$ |    " << endl;
	cout << "    $/     $$$$$$/  $$$$$$/     $$/     $$$$$$/  $$/   $$/     $$/     " << endl;
}

void omok_board::prt_lose()
{
	cout << " __         ______    ______   ________  " << endl;
	cout << "/  |       /      |  /      | /        |" << endl;
	cout << "$$ |      /$$$$$$  |/$$$$$$  |$$$$$$$$/ " << endl;
	cout << "$$ |      $$ |  $$ |$$ |__$$/ $$ |__    " << endl;
	cout << "$$ |      $$ |  $$ |$$      | $$    |   " << endl;
	cout << "$$ |      $$ |  $$ | $$$$$$  |$$$$$/    " << endl;
	cout << "$$ |_____ $$ |__$$ |/  |__$$ |$$ |_____ " << endl;
	cout << "$$       |$$    $$/ $$    $$/ $$       |" << endl;
	cout << "$$$$$$$$/  $$$$$$/   $$$$$$/  $$$$$$$$/" << endl;
}

void omok_board::prt_board_easy()
{
	cout << "  y  ";
	for (int i = 0; i < MAX_SIZE; i++)
		cout << setw(2) << i << " ";
	cout << endl;
	cout << "x   -----------------\n";
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << setw(2) << i << " | ";
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cout << setw(2) << main_board[i][j] << " ";
		}
		cout << "|";
		cout << endl;
	}
	cout << "    -----------------\n";
}

void omok_board::prt_board()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (main_board[i][j] == 0 && j == 0 && i == 0)
				cout << "┌-";
			else if (main_board[i][j] == 0 && j == 0 && i == MAX_SIZE - 1)
				cout << "└-";
			else if (main_board[i][j] == 0 && j == 0 && i != 0 && i != MAX_SIZE - 1)
				cout << "├-";
			else if (main_board[i][j] == 0 && j != 0 && j != MAX_SIZE - 1 && i != 0 && i != MAX_SIZE - 1)
				cout << "┼-";
			else if (main_board[i][j] == 0 && i == 0 && j != 0 && j != MAX_SIZE - 1)
				cout << "┬-";
			else if (main_board[i][j] == 0 && i == 0 && j == MAX_SIZE - 1)
				cout << "┐";
			else if (main_board[i][j] == 0 && i != 0 && i != MAX_SIZE - 1 && j == MAX_SIZE - 1)
				cout << "┤";
			else if (main_board[i][j] == 0 && i == MAX_SIZE - 1 && j != MAX_SIZE - 1 && j != 0)
				cout << "┴-";
			else if (main_board[i][j] == 0 && j == MAX_SIZE - 1 && i == MAX_SIZE - 1)
				cout << "┘";
			else if (main_board[i][j] == 1)
				cout << "○";
			else if (main_board[i][j] == 2)
				cout << "△";
			else if (main_board[i][j] == -1)
				cout << "●";
			else if (main_board[i][j] == -2)
				cout << "▲";
		}
		cout << "\n";
	}
	for (int j = 0; j < MAX_SIZE; j++)
	{
		if (main_board[MAX_SIZE][j] == 2)
			cout << "△";
		else if (main_board[MAX_SIZE][j] == -2)
			cout << "▲";
		else if (main_board[MAX_SIZE][j] == 0)
			cout << "  ";
	}
	cout << "\n";
}

int omok_board::user_input(int* x, int* y, int val)
{
	char user = 0;

	set_board(*x, *y, val * 2);
	while (user != 'r')
	{
		system("cls");
		prt_board();
		cout << "w, a, s, d로 이동후 r로 착수하세요" << endl;
		user = _getch();
		set_board(*x, *y, 0);
		if (user == 'w')
			if (!is_safe(*x - 1))
				*x = *x - 1;
		if (user == 'a')
			if (!is_safe(*y - 1))
				*y = *y - 1;
		if (user == 's')
			if (!is_safe(*x + 1))
				*x = *x + 1;
		if (user == 'd')
			if (!is_safe(*y + 1))
				*y = *y + 1;
		set_board(*x, *y, val * 2);
	}
	if (set_board(*x, *y, val))
		return 1;
	set_board(*x, *y, 0);
	system("cls");
	//prt_board_easy();
	prt_board();
	return 0;
}