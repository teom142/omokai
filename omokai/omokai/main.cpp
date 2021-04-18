#include "omok.h"
#include "omokai.h"
#include "omok_board.h"

int main()
{

	omokai omokai;
	omok_board omok_board;

	omok_board.init_board();
	omok_board.prt_board();
	int x = MAX_SIZE / 2, y = MAX_SIZE / 2;
	int x2 = MAX_SIZE / 2, y2 = MAX_SIZE / 2;
	int vic = omok_board.is_win();

	while (!vic)
	{
		if(!omok_board.user_input(&x, &y, 1))
			omokai.alloc_val(x, y, 10);
		vic = omok_board.is_win();
		cout << endl;
		//omokai.prt_val_voard();
	}
	omok_board.prt_victory();
}