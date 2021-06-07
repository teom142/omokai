/*omokai.h*/
#include "omok.h"
#include "omok_board.h"

#ifndef _OMOKAI_H
# define _OMOKAI_H

class omokai
{
	int val_board[MAX_SIZE][MAX_SIZE];

public:
	int ai_x;
	int ai_y;
	int ad_carry;

	omokai();
	void prt_val_voard();								//현재 가중치 출력
	void set_ai_xy(omok_board& bo);						//가중치를 기반으로 ai가 착수할 위치 선택 후 착수
	void alloc_val(int x, int y, int val);				//해당 돌 주변을 val가중치로 설정
	int is_safe_close(int x, int y, omok_board& bo);	//index한 위치가 open이면 0을, close 혹은 위치 밖이면 1을 반환
	void special_val(omok_board& bo);					//특정 가중치 부여
	void init_val_board();								//10으로 설정된 부분을 제외하고 가중치를 모두 0으로 설정

	//val : 30
	int close_2(int x, int y, omok_board& bo, int val);
	//val : 40
	int open_2(int x, int y, omok_board& bo, int val);
	//val : 60
	int close_3(int x, int y, omok_board& bo, int val);
	//val : 300
	int open_3(int x, int y, omok_board& bo, int val);
	//val : 400
	int close_4(int x, int y, omok_board& bo, int val);
	//val : 370
	int space_3(int x, int y, omok_board& bo, int val);
	//val : 450
	int space_4(int x, int y, omok_board& bo, int val);

	//val : 150
	int ai_space_2(int x, int y, omok_board& bo, int val);
	//val : 170
	int ai_open_2(int x, int y, omok_board& bo, int val);
	//val : 330
	int ai_close_3(int x, int y, omok_board& bo, int val);
	//val : 350
	int ai_space_3(int x, int y, omok_board& bo, int val);
	//val : 380
	int ai_open_3(int x, int y, omok_board& bo, int val);
	//val : 998
	int ai_close_4(int x, int y, omok_board& bo, int val);
	//val : 999
	int ai_open_4(int x, int y, omok_board& bo, int val);
};

#endif