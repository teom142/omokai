#include "omok.h"
#include "omok_board.h"

#ifndef _OMOKAI_H
# define _OMOKAI_H

class omokai
{
	int val_board[MAX_SIZE][MAX_SIZE] = {};


public:
	int ai_x;
	int ai_y;

	friend int omok_board::get_board_dol(int x, int y);
	omokai();
	void prt_val_voard();
	void set_ai_xy(omok_board& bo);
	void alloc_val(int x, int y, int val);
	int is_safe_close(int x, int y, omok_board& bo);
	void special_val(omok_board& bo);
	void init_val_board();

	//val : 20
	int close_2(int x, int y, omok_board& bo);
	//val : 40
	int open_2(int x, int y, omok_board& bo);
	//val : 60
	int close_3(int x, int y, omok_board& bo);
	//val : 200
	int open_3(int x, int y, omok_board& bo);
	//val : 400
	int close_4(int x, int y, omok_board& bo);

	//val : 350
	int ai_close_3(int x, int y, omok_board& bo);
	//val : 380
	int ai_open_3(int x, int y, omok_board& bo);	
	//val : 2000
	int ai_close_4(int x, int y, omok_board& bo);
};

#endif