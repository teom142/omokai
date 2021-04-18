#include "omok.h"

#ifndef _OMOKAI_H
# define _OMOKAI_H

class omokai
{
	int val_board[MAX_SIZE][MAX_SIZE] = {};
	
public:
	omokai()
	{

	}

	void prt_val_voard()
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			for (int j = 0; j < MAX_SIZE; j++)
				cout << setw(4) << val_board[i][j];
			cout << endl;
		}
	}

	void alloc_val(int x, int y, int val)
	{
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
				if (i != 0 || j != 0)
					if (!is_safe(x + i) && !is_safe(y + i))
						val_board[x + i][y + j] += val;
	}

};

#endif