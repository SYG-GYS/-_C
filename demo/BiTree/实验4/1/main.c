#include "BiTree.h"

int main()
{
	int A=0, _case;
	char B;
	printf("创建链式二叉树：");
	BiTree T = Creat_BiTree();
	while (1)
	{
		printf("请选择操作：\n1.先序、中序、后序遍历  2.查找结点X  3.叶子总数  4.结点总数  5.二叉树高度  6.退出\n");
		scanf_s("%d", &_case);
		switch (_case)
		{
		case 1:
			printf("先序遍历：");
			Pre_order(T);
			printf("\n");
			printf("中序遍历：");
			In_order(T);
			printf("\n");
			printf("后序遍历：");
			Post_order(T);
			printf("\n");
			break;
		case 2:
			getchar();
			printf("输入X元素：");
			scanf_s("%c",&B,1);
			Stack S= (Stack)malloc(sizeof(SeqStack));
			S->top = -1;
			Sreach(T, B, S);
			Action(T, B, S);
			break;
		case 3:
            A=Lsum_BiTree(T);
			printf("叶子总数：%d\n",A);
			break;
		case 4:
			A = Sum_BiTree(T);
			printf("结点总数：%d\n",A);
			break;
		case 5:
			A = High_BiTree(T);
			printf("二叉树高度:%d\n",A);
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	}
	return 0;
}