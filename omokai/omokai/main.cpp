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
		cin >> omokai.ad_carry;		//ai의 공격성 입력
	} while (omokai.ad_carry < 1 || omokai.ad_carry > 6);
	omok_board.prt_board();

	while (!vic)
	{
		while (!omok_board.user_input(&x, &y, 1));		//사용자 입력 성공적으로 착수할  때 까지 반복
		omokai.alloc_val(x, y, 10);						//주변 위치의 가중치를 10으로 설정
		vic = omok_board.is_win();						//사용자 착수 후 게임이 종료되었는지 검사
		if(!vic)										//게임이 종료되지 않았으면 ai착수 시작
		{
			omokai.special_val(omok_board);					//특별 가중치 값 부여
			omokai.set_ai_xy(omok_board);					//가중치에 따라 ai가 착수할 위치 설정
			omok_board.set_board(omokai.ai_x, omokai.ai_y, -1);	//ai가 설정한 위치를 -1로 ai착수
		}
		vic = omok_board.is_win();
		cout << endl;
	}
	system("cls");
	omok_board.prt_board();
	if (vic == 1)
		omok_board.prt_victory();
	else
		omok_board.prt_lose();

}