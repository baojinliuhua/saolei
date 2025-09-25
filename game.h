#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>
//是否可以通过获得值再判断结合定义常量来使棋盘大小可自选
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10
//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//布置雷
void SetMine(char mine[ROWS][COLS], int row,int col);
//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//统计雷的数量
int GetMine(char mine[ROWS][COLS], int x, int y);