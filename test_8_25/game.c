#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//游戏说明
void Explain() {
	printf("这是一个常规的扫雷游戏\n"
			"玩家需要根据棋盘输入对应的 数字坐标 才能在对应的位置进行排雷\n。"
			"当然玩家可输入上一次排雷的坐标（这么做毫无意义 *-*）\n\n"
			"排雷：玩 家 在 对 应  位 置 排 雷 会 "
		"在 安 全 区 域 显 示 附 近 的 地 雷 的 个 数\n\n"
		"雷的图标  “#” "
			"游戏结束判定:玩家踩雷直接 出局，若玩家安全的排查完所有无雷区则 胜出。\n");
}

//游戏运行
void Game() {
	char j[ROWS][COLS] = { 0 };//内部棋盘
	char f[ROWS][COLS] = { 0 };//外显棋盘
	
	//初始化
	Initialize(&j, ROWS, COLS, '0');
	Initialize(&f, ROWS, COLS, '*');
	//埋雷
	Putmine(&j, ROW, COL); 
	int d = 0;
	do
	{	
		
		 //打印内棋盘
		// Nei(&j, ROWS, COLS);
		//打印外显棋盘
		 Printf(&f,ROW,COL);
		////玩家排雷
		 Plisyer(&j,&f,ROW,COL);
		 //打印内棋盘
		 Nei(&j, ROWS, COLS);
		 //打印外显棋盘
		 Printf(&f, ROW, COL);
		////判断是否结束
		 d = Ifend(&j,&f,ROW,COL);

	} while (d);
}
//埋雷
void Putmine(char(*p)[ROWS][COLS], int row, int col) {
	int cou = LIE;
	srand((unsigned int)time(NULL));
	
	do {
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;//1-9
		if ((*p)[x][y] == '0') {
			(*p)[x][y] = '1';
			--cou;
		}
	} while (cou!=0);
	
 }
//打印内棋盘
void Nei(char(*p)[ROWS][COLS], int row, int col) {
	printf("雷数#：10\n");
	for (int i = 0; i < row; i++) {
		
		for (int j = 0; j <col; j++) {
		
			printf("%c ", (*p)[i][j]);
		}
		printf("\n");
	}
}
//打印外显棋盘
void Printf( char(*p)[ROWS][COLS], int row, int col) {
	printf("雷数#：10\n");
	for (int k = 0; k <= col; k++) {
		printf(" %d", k);
	}
	printf("\n");
	for (int k = 0; k <= col; k++) {
		printf(" -- ");
	}
	printf("\n");
	for (int i = 1; i <= row; i++) {
		printf(" %d|",i);
		for (int j = 1; j <= col; j++) {
			
			printf("%c ", (*p)[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
//玩家排雷
void Plisyer(char(*j)[ROWS][COLS], char(*f)[ROWS][COLS], int row, int col) {
	int a = 0;
	int b = 0;
	printf("请输入坐标\n");
	scanf("%d", &a);
	scanf("%d", &b);
	while ((a>row||a<=0 ) || (b > col|| b <= 0))
	{
		printf("输入错误，请重新输入\n");
		char q[20] = "";
		gets(q);
		scanf("%d", &a);
		scanf("%d", &b);
	}
	showadd((*j), (*f), row, col, a,b);
}
//找雷
char Find(char(*j)[ROWS][COLS], char(*f)[ROWS][COLS], int row, int col,int a,int b) {
	if ((*j)[a][b] == (char)'1') {
		printf("  bo! ，你已被炸的稀烂  *-* \n") ;
		return (char)'#';
	}
	else {

		char d = (*j)[a - 1][b - 1] +
			(*j)[a - 1][b] +
			(*j)[a - 1][b + 1] +
			(*j)[a][b - 1] +
			
			(*j)[a][b + 1] +
			(*j)[a + 1][b - 1] +
			(*j)[a + 1][b] +
			(*j)[a + 1][b + 1] - 8 * '0'+'0';

		return d;
			
			
	}
		
}

//判断是否结束
int Ifend(char(*j)[ROW][COL],char(*f)[ROW][COL], int row, int col) {
	char c = 0;
	for (int i = 1; i <= row; i++) {
		for (int g = 1; g <= col; g++) {
			if ((*f)[i][g] != '*') {
				if ((*f)[i][g] == '#') {
					printf("游戏结束\n");
					Look((*j),row,col);
					return 0;
				}
				else {
					c++;
				}
			}
		}
	}
	if (c == row * col - LIE) {
		printf("恭喜! 成功通关\n");
		printf("游戏结束\n");
		Look((*j), row, col);
		return 0;
	}
	else {
		return 1;
	}
}


//数组初始化
void Initialize(char (*p)[ROWS][COLS],int hang,int lie,char set) {
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {
			(*p)[i][j] = (char)set;
		}
	}
}
//扩展
void showadd(char(*j)[ROWS][COLS], char(*f)[ROWS][COLS], int row, int col, int a,int b) {
	if ((a <= row && a>0) && (b <= col && b>0)) {
		char s = '0';
		s =	Find((*j), (*f), row, col, a,b);
		if (s != '#') {
			if ((*j)[a - 1][b - 1] +
				(*j)[a - 1][b] +
				(*j)[a - 1][b + 1] +
				(*j)[a][b - 1] +
				(*j)[a][b + 1] +
				(*j)[a + 1][b - 1] +
				(*j)[a + 1][b] +
				(*j)[a + 1][b + 1] - 8 * '0' == 0) {

				(*f)[a - 1][b - 1] = '0';
				(*f)[a - 1][b] = '0';
				(*f)[a - 1][b + 1] = '0';
				(*f)[a][a - 1] = '0';
				(*f)[a][a + 1] = '0';
				(*f)[a + 1][b - 1] = '0';
				(*f)[a + 1][b] = '0';
				(*f)[a + 1][b + 1] = '0';
				//	char s = Find((*j), (*f), row, col, a);
				showadd((*j), (*f), row, col, a + 1, b);

			}
		
		}
		(*f)[a][b] = s;
	}
}


//玩家查看雷阵
void Look(char(*j)[ROWS][COLS], int row, int col) {
	printf("亲，你已有身亡，以下是全部雷的位置\n");
	printf("雷数#：10\n");
	for (int k = 0; k <= col; k++) {
		printf(" %d", k);
	}
	printf("\n");
	for (int k = 0; k <= col; k++) {
		printf(" -- ");
	}
	printf("\n");
	for (int i = 1; i <= row; i++) {
		printf(" %d|", i);
		for (int g = 1; g <= col; g++) {

			printf("%c ", (*j)[i][g]);
		}
		printf("\n");
	}
	printf("\n\n");
}