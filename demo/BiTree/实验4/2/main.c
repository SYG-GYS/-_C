#include "BiTree.h"

int main()
{
	int n, A = 1, _case;
	printf("����ڵ���n��");
	scanf_s("%d", &n);
	char str[1024];
	printf("�������飺");
	scanf_s("%s", str,1024);
	BiTree T = Creat_BiTree(str, n, A);
	while (1)
	{
		printf("��ѡ�������\n1.����������ǵݹ飩  2.������������ 3.���Ʋ�������TΪT2  4.�˳�\n");
		scanf_s("%d", &_case);
		switch (_case)
		{
		case 1:
			printf("����������ǵݹ飩��");
			NRPreOrder(T);
			printf("\n");
			break;
		case 2:
			printf("�����ɹ���\n");
			Change_child(T);
			break;
		case 3:
			printf("���Ƴɹ���   ");
			BiThrTree T2=Copy_BiTree(T);
			printf("�����������飩��");
			Pre_orders(T2);
			printf("   �������ɹ���");
			T2 = InOrderThr(T2);
			printf("\n");
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}
}