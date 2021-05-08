#include "omok.h"
#include "omokai.h"
#include "omok_board.h"

int main()
{
	omokai omokai;
	omok_board omok_board;

	omok_board.init_board();
	int x = MAX_SIZE / 2, y = MAX_SIZE / 2;
	int x2 = MAX_SIZE / 2, y2 = MAX_SIZE / 2;
	int vic = omok_board.is_win();
	do {
		cout << "인공지능의 공격성을 입력해주세요. (1 ~ 6 입력)\n참고로 5가 최고 난이도입니다 :)";
		cin >> omokai.ad_carry;
	} while (omokai.ad_carry < 1 || omokai.ad_carry > 6);
	omok_board.prt_board();

	while (!vic)
	{
		while (!omok_board.user_input(&x, &y, 1));
		omokai.alloc_val(x, y, 10);
		vic = omok_board.is_win();
		omokai.special_val(omok_board);
		//omokai.prt_val_voard();
		omokai.set_ai_xy(omok_board);
		if (!vic)
			omok_board.set_board(omokai.ai_x, omokai.ai_y, -1);
		vic = omok_board.is_win();
		cout << endl;
	}
	system("cls");
	omok_board.prt_board();
	//prt_thumbs_up();
	if (vic == 1)
		omok_board.prt_victory();
	else
		omok_board.prt_lose();

}