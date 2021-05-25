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

	friend int omok_board::get_board_dol(int x, int y);
	omokai();
	void prt_val_voard();
	void set_ai_xy(omok_board& bo);
	void alloc_val(int x, int y, int val);
	int is_safe_close(int x, int y, omok_board& bo);
	void special_val(omok_board& bo);
	void init_val_board();

	//val : 20
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
	//val : 2000
	int ai_close_4(int x, int y, omok_board& bo, int val);
};

#endif