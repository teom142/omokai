#include "omok_board.h"

omok_board::omok_board()
{
	aix = -1;
	aiy = -1;

	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			main_board[i][j] = 0;
}

int omok_board::get_board_dol(int x, int y)
{
	return main_board[x][y];
}

int omok_board::set_board(int x, int y, int val)
{
	if (is_safe(x) || is_safe(y) || main_board[x][y] == -1 || main_board[x][y] == 1)
		return 1;				//해당 위치가 -1 또는 1일경우 (com이나 플레이어가 착수했을 경우)값을 입력하지 않고 1을 반환
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

void omok_board::prt_board()
{
	for (int i = 0; i < MAX_SIZE; i++)		//main_board의 값의 따라 오목판을 출력해주는 함수
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
		}
		cout << "\n";
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
			if (!is_safe(*x - 1))		//사용자가 이동하려는 방향이 오목판을 벗어나는지 확인한 후
				*x = *x - 1;			//커서를 이동한다.
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
	if (aix != -1 && aiy != -1)
		main_board[aix][aiy] = -1;
	if (!set_board(*x, *y, val))		//set_board()의 반환값에 따라 착수를 성공적으로 했는지 못했는지 알 수 있다
		return 1;
	cout << "해당 위치는 이미 돌이 놓여 있습니다\n아무 키 입력 후 재 착수";
	user = _getch();
	return 0;
}