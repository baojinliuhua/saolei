#include"game.h"
void menu()
{
	printf("*********************************\n");
	printf("************1.play***************\n");
	printf("************0.exit***************\n");
	printf("*********************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };//����׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų�����Ϣ
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(show, ROW, COL);
	

	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//�Ų��ף��������꣬1���ж��Ƿ�Խ��2���ж��ǲ����ף�����ֱ������������ͳ��������
	FindMine(mine, show, ROW, COL);
}



void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������");
			break;
		}
	} while (input);

}
int main()
{
	test();
	return 0;
}