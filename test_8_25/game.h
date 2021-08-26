#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS  ROW  +2
#define COLS  COL  +2
#define LIE 10

//插雷
void Putmine(char(*p)[ROWS][COLS], int row, int col);
//打印内棋盘
void Nei(char(*p)[ROWS][COLS], int row, int col);
//打印外显棋盘
void Printf( char(*p)[ROWS][COLS], int row, int col);
//玩家排雷
void Plisyer(char(*j)[ROWS][COLS], char(*f)[ROWS][COLS], int row, int col);
//找雷
char Find(char(*j)[ROWS][COLS], char(*f)[ROWS][COLS], int row, int col, int a,int b);
//判断是否结束
int Ifend(char(*j)[ROW][COL], char(*f)[ROW][COL], int row, int col);
//游戏说明
void Explain();

//游戏运行
void Game();

//游戏菜单
void Gamemenue();

//数组初始化
void Initialize(char(*p)[ROWS][COLS], int hang, int lie,char set);
//扩展
void showadd(char(*j)[ROWS][COLS], char(*f)[ROWS][COLS], int row, int col, int a,int b);
//玩家查看雷阵
void Look(char(*j)[ROWS][COLS], int row, int col);