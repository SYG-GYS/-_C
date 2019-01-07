#include "BiTree.h"

//创建二叉树
BiTree Creat_BiTree()
{
	BiTree T;
	char ch;
	scanf_s("%c", &ch,1);
	if (ch == '0')
		T = NULL;
	else
	{
		T = (BiNode *)malloc(sizeof(BiNode));
		if (T)
		{
			T->data = ch;
			T->lchild=Creat_BiTree();
			T->rchild=Creat_BiTree();
		}
	}
	return T;
}
//先序遍历
void Pre_order(BiTree T)
{
	if (T)
	{
		printf("%c", T->data);
		Pre_order(T->lchild);
		Pre_order(T->rchild);
	}
}
//中序遍历
void In_order(BiTree T)
{
	if (T)
	{
		In_order(T->lchild);
		printf("%c", T->data);
		In_order(T->rchild);
	}
}
//后序遍历
void Post_order(BiTree T)
{
	if (T)
	{
		Post_order(T->lchild);
		Post_order(T->rchild);
		printf("%c", T->data);
	}
}
//查找元素X
int Sreach(BiTree T, char X, Stack S)
{
	if (T)
	{
		if (T->data == X)
		{
			S->top++;
			S->data[S->top] = T;
		}
		Sreach(T->lchild, X, S);
		Sreach(T->rchild, X, S);
	}
}
//指定操作
void Action(BiTree T, char B, Stack S)
{
	int _case;
	if (S->top != -1)
	{
		if (S->top > 0)
		{
			printf("共%d个%c元素，选择一个元素（填序号）：", S->top + 1, B);
			scanf_s("%d", &S->top, 1);
			S->top = S->top - 1;
		}
		printf("选择一个操作：1、插入  2、删除  （其他数字不操作）\n");
		scanf_s("%d", &_case);
		getchar();
		switch (_case)
		{
		case 1:
			printf("输入插入的元素：");
			scanf_s("%c", &B, 1);
			InsertL(T, B, S);
			printf("插入成功!");
			break;
		case 2:
			DeleteL(S->data[S->top]);
			printf("删除成功!");
			break;
		}
	}
	else printf("该元素不存在\n");
}
//插入元素
void InsertL(BiTree T,char x, Stack S)
{
	BiTree p;
	if (p = (BiTree)malloc(sizeof(BiNode)))
	{
		p->data = x;
		p->lchild = S->data[S->top]->lchild;
		p->rchild = S->data[S->top]->rchild;
		S->data[S->top]->lchild = p;
		S->data[S->top]->rchild = NULL;
	}
}
//删除X元素的子树
void DeleteL(BiTree T)
{
		Delete(T->lchild);
		Delete(T->rchild);
		T->lchild = NULL;
		T->rchild = NULL;
}
void Delete(BiTree T)
{
	if (T)
	{
		Delete(T->lchild);
		Delete(T->rchild);
	}
	free(T);
}
//二叉树叶子数
int Lsum_BiTree(BiTree T)
{
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	return Lsum_BiTree(T->lchild) + Lsum_BiTree(T->rchild);
}
//二叉树结点数
int Sum_BiTree(BiTree T)
{
	if (T)
	return Sum_BiTree(T->lchild) + Sum_BiTree(T->rchild)+1;
	else 
	return 0;
}
//二叉树高度
int High_BiTree(BiTree T)
{
	int treeHeight = 0;
	if (T != NULL)
	{
		int leftHeight = High_BiTree(T->lchild);
		int rightHeight = High_BiTree(T->rchild);
		treeHeight = leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	return treeHeight;
}