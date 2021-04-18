#include "omok.h"

#ifndef _OMOKAI_H
# define _OMOKAI_H

class omokai
{
	int val_board[MAX_SIZE][MAX_SIZE] = {};
	
public:
	omokai();
	void prt_val_voard();
	void alloc_val(int x, int y, int val);

};

#endif