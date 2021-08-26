#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//��Ϸ˵��
void Explain() {
	printf("����һ�������ɨ����Ϸ\n"
			"�����Ҫ�������������Ӧ�� �������� �����ڶ�Ӧ��λ�ý�������\n��"
			"��Ȼ��ҿ�������һ�����׵����꣨��ô���������� *-*��\n\n"
			"���ף��� �� �� �� Ӧ  λ �� �� �� �� "
		"�� �� ȫ �� �� �� ʾ �� �� �� �� �� �� �� ��\n\n"
		"�׵�ͼ��  ��#�� "
			"��Ϸ�����ж�:��Ҳ���ֱ�� ���֣�����Ұ�ȫ���Ų��������������� ʤ����\n");
}

//��Ϸ����
void Game() {
	char j[ROWS][COLS] = { 0 };//�ڲ�����
	char f[ROWS][COLS] = { 0 };//��������
	
	//��ʼ��
	Initialize(&j, ROWS, COLS, '0');
	Initialize(&f, ROWS, COLS, '*');
	//����
	Putmine(&j, ROW, COL); 
	int d = 0;
	do
	{	
		
		 //��ӡ������
		// Nei(&j, ROWS, COLS);
		//��ӡ��������
		 Printf(&f,ROW,COL);
		////�������
		 Plisyer(&j,&f,ROW,COL);
		 //��ӡ������
		 Nei(&j, ROWS, COLS);
		 //��ӡ��������
		 Printf(&f, ROW, COL);
		////�ж��Ƿ����
		 d = Ifend(&j,&f,ROW,COL);

	} while (d);
}
//����
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
//��ӡ������
void Nei(char(*p)[ROWS][COLS], int row, int col) {
	printf("����#��10\n");
	for (int i = 0; i < row; i++) {
		
		for (int j = 0; j <col; j++) {
		
			printf("%c ", (*p)[i][j]);
		}
		printf("\n");
	}
}
//��ӡ��������
void Printf( char(*p)[ROWS][COLS], int row, int col) {
	printf("����#��10\n");
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
//�������
void Plisyer(char(*j)[ROWS][COLS], char(*f)[ROWS][COLS], int row, int col) {
	int a = 0;
	int b = 0;
	printf("����������\n");
	scanf("%d", &a);
	scanf("%d", &b);
	while ((a>row||a<=0 ) || (b > col|| b <= 0))
	{
		printf("�����������������\n");
		char q[20] = "";
		gets(q);
		scanf("%d", &a);
		scanf("%d", &b);
	}
	showadd((*j), (*f), row, col, a,b);
}
//����
char Find(char(*j)[ROWS][COLS], char(*f)[ROWS][COLS], int row, int col,int a,int b) {
	if ((*j)[a][b] == (char)'1') {
		printf("  bo! �����ѱ�ը��ϡ��  *-* \n") ;
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

//�ж��Ƿ����
int Ifend(char(*j)[ROW][COL],char(*f)[ROW][COL], int row, int col) {
	char c = 0;
	for (int i = 1; i <= row; i++) {
		for (int g = 1; g <= col; g++) {
			if ((*f)[i][g] != '*') {
				if ((*f)[i][g] == '#') {
					printf("��Ϸ����\n");
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
		printf("��ϲ! �ɹ�ͨ��\n");
		printf("��Ϸ����\n");
		Look((*j), row, col);
		return 0;
	}
	else {
		return 1;
	}
}


//�����ʼ��
void Initialize(char (*p)[ROWS][COLS],int hang,int lie,char set) {
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {
			(*p)[i][j] = (char)set;
		}
	}
}
//��չ
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


//��Ҳ鿴����
void Look(char(*j)[ROWS][COLS], int row, int col) {
	printf("�ף�������������������ȫ���׵�λ��\n");
	printf("����#��10\n");
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