#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS  ROW  +2
#define COLS  COL  +2
#define LIE 10

//����
void Putmine(char(*p)[ROWS][COLS], int row, int col);
//��ӡ������
void Nei(char(*p)[ROWS][COLS], int row, int col);
//��ӡ��������
void Printf( char(*p)[ROWS][COLS], int row, int col);
//�������
void Plisyer(char(*j)[ROWS][COLS], char(*f)[ROWS][COLS], int row, int col);
//����
char Find(char(*j)[ROWS][COLS], char(*f)[ROWS][COLS], int row, int col, int a,int b);
//�ж��Ƿ����
int Ifend(char(*j)[ROW][COL], char(*f)[ROW][COL], int row, int col);
//��Ϸ˵��
void Explain();

//��Ϸ����
void Game();

//��Ϸ�˵�
void Gamemenue();

//�����ʼ��
void Initialize(char(*p)[ROWS][COLS], int hang, int lie,char set);
//��չ
void showadd(char(*j)[ROWS][COLS], char(*f)[ROWS][COLS], int row, int col, int a,int b);
//��Ҳ鿴����
void Look(char(*j)[ROWS][COLS], int row, int col);