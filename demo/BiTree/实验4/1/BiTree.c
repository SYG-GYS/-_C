#include "BiTree.h"

//����������
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
//�������
void Pre_order(BiTree T)
{
	if (T)
	{
		printf("%c", T->data);
		Pre_order(T->lchild);
		Pre_order(T->rchild);
	}
}
//�������
void In_order(BiTree T)
{
	if (T)
	{
		In_order(T->lchild);
		printf("%c", T->data);
		In_order(T->rchild);
	}
}
//�������
void Post_order(BiTree T)
{
	if (T)
	{
		Post_order(T->lchild);
		Post_order(T->rchild);
		printf("%c", T->data);
	}
}
//����Ԫ��X
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
//ָ������
void Action(BiTree T, char B, Stack S)
{
	int _case;
	if (S->top != -1)
	{
		if (S->top > 0)
		{
			printf("��%d��%cԪ�أ�ѡ��һ��Ԫ�أ�����ţ���", S->top + 1, B);
			scanf_s("%d", &S->top, 1);
			S->top = S->top - 1;
		}
		printf("ѡ��һ��������1������  2��ɾ��  ���������ֲ�������\n");
		scanf_s("%d", &_case);
		getchar();
		switch (_case)
		{
		case 1:
			printf("��������Ԫ�أ�");
			scanf_s("%c", &B, 1);
			InsertL(T, B, S);
			printf("����ɹ�!");
			break;
		case 2:
			DeleteL(S->data[S->top]);
			printf("ɾ���ɹ�!");
			break;
		}
	}
	else printf("��Ԫ�ز�����\n");
}
//����Ԫ��
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
//ɾ��XԪ�ص�����
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
//������Ҷ����
int Lsum_BiTree(BiTree T)
{
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	return Lsum_BiTree(T->lchild) + Lsum_BiTree(T->rchild);
}
//�����������
int Sum_BiTree(BiTree T)
{
	if (T)
	return Sum_BiTree(T->lchild) + Sum_BiTree(T->rchild)+1;
	else 
	return 0;
}
//�������߶�
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