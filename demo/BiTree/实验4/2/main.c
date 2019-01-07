#include "BiTree.h"

int main()
{
	int n, A = 1, _case;
	printf("输入节点数n：");
	scanf_s("%d", &n);
	char str[1024];
	printf("输入数组：");
	scanf_s("%s", str,1024);
	BiTree T = Creat_BiTree(str, n, A);
	while (1)
	{
		printf("请选择操作：\n1.先序遍历（非递归）  2.交换左右子树 3.复制并线索化T为T2  4.退出\n");
		scanf_s("%d", &_case);
		switch (_case)
		{
		case 1:
			printf("先序遍历（非递归）：");
			NRPreOrder(T);
			printf("\n");
			break;
		case 2:
			printf("交换成功！\n");
			Change_child(T);
			break;
		case 3:
			printf("复制成功！   ");
			BiThrTree T2=Copy_BiTree(T);
			printf("先序遍历（检查）：");
			Pre_orders(T2);
			printf("   线索化成功！");
			T2 = InOrderThr(T2);
			printf("\n");
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	}
}