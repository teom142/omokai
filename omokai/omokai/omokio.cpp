#include "omok.h"
#include "omok_board.h"
#include "omokai.h"

void omok_board::prt_victory()
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

void omok_board::user_input(int *x, int *y, int val)
{
	char user = 0;

	set_board(*x, *y, val*2);
	while (user != 'r')
	{
		system("cls");
		prt_board();
		cout << "w, a, s, d로 이동후 r로 착수하세요" << endl;
		user = getch();
		set_board(*x, *y, 0);
		if (user == 'w')
			if (!is_safe(*x - 2))
				*x = *x - 1;
		if (user == 'a')
			if (!is_safe(*y - 1))
				*y = *y - 1;
		if (user == 's')
			if (!is_safe(*x))
				*x = *x + 1;
		if (user == 'd')
			if (!is_safe(*y + 1))
				*y = *y + 1;
		set_board(*x, *y, val*2);
	}
	set_board(*x-1, *y, val);
	set_board(*x, *y, 0);
	system("cls");
	prt_board();
}