#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//游戏菜单
void Gamemenue() {
	printf("------**** 扫雷 ****-------\n");
	printf("----------------------------\n");
	printf("--------1.开始游戏---------\n");
	printf("--------2.游戏说明---------\n");
	printf("--------3.退出游戏---------\n");
	printf("----------------------------\n");
}
void test() {
	int a = 0;
	
	do {
		Gamemenue();
		printf("请输入选项\n");
		scanf("%d",&a);

		switch (a) {
		case 1:			//玩游戏
			Game();
			break;
		case 2:	Explain();	//说明
			break;
		case 3:
			break;   //退出
		case 4:
			printf("输入错误\n");
			break;//输入错误
		}
	} while (a!=3);
}
int main() {
	test();
	return 0;
}