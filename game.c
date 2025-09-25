#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0, j = 0;
	for (i=0; i < rows; i++)
	{
		for (j=0; j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("--------扫雷-------\n");
	int i = 0, j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i );
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count=EASY_COUNT;
	int x = 0, y = 0;
	srand((unsigned int)time(NULL));
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] != '1')
		{
			mine[x][y] = '1';
			count--;
		}
		
	}
}

int GetMine(char mine[ROWS][COLS], int x, int y)
{
	
	/*比较笨的办法return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x = 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';*/
	int count = 0;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			count += mine[x+i][y+j]-'0';
		}
	}
	return count;

	 
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0, win = 0;
	while (1)
    {
		printf("请输入要排查的坐标");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')//是雷
			{
				printf("很遗憾你踩雷了，游戏结束");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else//不是雷
			{
				int count = GetMine(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
	    else
		{
			printf("输入坐标有误,请重新输入");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}



