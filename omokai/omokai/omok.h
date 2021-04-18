#ifndef _OMOK_H__
#define _OMOK_H__
# include <iostream>
# include <conio.h>
# include <iomanip>
# define MAX_SIZE 19

using namespace std;
			
int is_safe(int n);									//n이 index범위를 벗어나면 1을 반환한다.
int con_dol(int dire, int x, int y, int num, int open);		//[x][y]로 부터 num만큼 dire이 1이면 가로, 2이면 세로, 3이면 대각선을 검사한다.

#endif