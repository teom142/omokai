#ifndef _OMOK_H__
#define _OMOK_H__
# include <iostream>
# include <conio.h>
# include <iomanip>
# define MAX_SIZE 19

using namespace std;
			
int is_safe(int n);									//n�� index������ ����� 1�� ��ȯ�Ѵ�.
int con_dol(int dire, int x, int y, int num, int main_board[MAX_SIZE + 1][MAX_SIZE]);		//[x][y]�� ���� num��ŭ dire�� 1�̸� ����, 2�̸� ����, 3�̸� ������ �밢����, 4�̸� ������ �밢���� �˻��Ѵ�.

#endif