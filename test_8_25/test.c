#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//��Ϸ�˵�
void Gamemenue() {
	printf("------**** ɨ�� ****-------\n");
	printf("----------------------------\n");
	printf("--------1.��ʼ��Ϸ---------\n");
	printf("--------2.��Ϸ˵��---------\n");
	printf("--------3.�˳���Ϸ---------\n");
	printf("----------------------------\n");
}
void test() {
	int a = 0;
	
	do {
		Gamemenue();
		printf("������ѡ��\n");
		scanf("%d",&a);

		switch (a) {
		case 1:			//����Ϸ
			Game();
			break;
		case 2:	Explain();	//˵��
			break;
		case 3:
			break;   //�˳�
		case 4:
			printf("�������\n");
			break;//�������
		}
	} while (a!=3);
}
int main() {
	test();
	return 0;
}