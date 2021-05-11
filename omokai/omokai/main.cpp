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
		cout << "�ΰ������� ���ݼ��� �Է����ּ���. (1 ~ 6 �Է�)\n����� 5�� �ְ� ���̵��Դϴ� :)";
		cin >> omokai.ad_carry;		//ai�� ���ݼ� �Է�
	} while (omokai.ad_carry < 1 || omokai.ad_carry > 6);
	omok_board.prt_board();

	while (!vic)
	{
		while (!omok_board.user_input(&x, &y, 1));		//����� �Է� ���������� ������  �� ���� �ݺ�
		omokai.alloc_val(x, y, 10);						//�ֺ� ��ġ�� ����ġ�� 10���� ����
		vic = omok_board.is_win();						//����� ���� �� ������ ����Ǿ����� �˻�
		if(!vic)										//������ ������� �ʾ����� ai���� ����
		{
			omokai.special_val(omok_board);					//Ư�� ����ġ �� �ο�
			omokai.set_ai_xy(omok_board);					//����ġ�� ���� ai�� ������ ��ġ ����
			omok_board.set_board(omokai.ai_x, omokai.ai_y, -1);	//ai�� ������ ��ġ�� -1�� ai����
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