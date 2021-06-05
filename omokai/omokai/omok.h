#ifndef _OMOK_H__
#define _OMOK_H__
# include <iostream>
# include <conio.h>
# include <iomanip>
# include <cstdlib>
# include<ctime>
# define MAX_SIZE 19

using namespace std;

int is_safe(int n);									//n이 index범위를 벗어나면 1을 반환한다.
int con_dol(int dire, int x, int y, int num, int main_board[MAX_SIZE + 1][MAX_SIZE]);		//[x][y]로 부터 num만큼 dire이 1이면 가로, 2이면 세로, 3이면 우하향 대각선을, 4이면 좌하향 대각선을 검사한다.
int con_dol_with_space(int dire, int x, int y, int num, int main_board[MAX_SIZE + 1][MAX_SIZE]);		//con_dol함수의 응용 함수로, 중간에 빈칸이 있어도 이어서 카운트 한다.
void prt_thumbs_up();

#endif