#include "BiTree.h"

int main()
{
	int A=0, _case;
	char B;
	printf("������ʽ��������");
	BiTree T = Creat_BiTree();
	while (1)
	{
		printf("��ѡ�������\n1.�������򡢺������  2.���ҽ��X  3.Ҷ������  4.�������  5.�������߶�  6.�˳�\n");
		scanf_s("%d", &_case);
		switch (_case)
		{
		case 1:
			printf("���������");
			Pre_order(T);
			printf("\n");
			printf("���������");
			In_order(T);
			printf("\n");
			printf("���������");
			Post_order(T);
			printf("\n");
			break;
		case 2:
			getchar();
			printf("����XԪ�أ�");
			scanf_s("%c",&B,1);
			Stack S= (Stack)malloc(sizeof(SeqStack));
			S->top = -1;
			Sreach(T, B, S);
			Action(T, B, S);
			break;
		case 3:
            A=Lsum_BiTree(T);
			printf("Ҷ��������%d\n",A);
			break;
		case 4:
			A = Sum_BiTree(T);
			printf("���������%d\n",A);
			break;
		case 5:
			A = High_BiTree(T);
			printf("�������߶�:%d\n",A);
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}
	return 0;
}