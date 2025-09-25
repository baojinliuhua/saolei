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
	char mine[ROWS][COLS] = { 0 };//存放雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查后的信息
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(show, ROW, COL);
	

	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//排查雷（输入坐标，1·判断是否越界2·判断是不是雷，是雷直接死，不是雷统计数量）
	FindMine(mine, show, ROW, COL);
}



void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误");
			break;
		}
	} while (input);

}
int main()
{
	test();
	return 0;
}