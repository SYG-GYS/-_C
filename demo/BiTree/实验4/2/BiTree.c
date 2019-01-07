#include "BiTree.h"

BiThrNodeType *p;

//����������
BiTree Creat_BiTree(char str[], int n,int A)
{
		BiTree T;
		T = (BiNode *)malloc(sizeof(BiNode));
		if (T)
		{
			T->data = str[A-1];
			A = A + A;
			if (A <= n)
				T->lchild = Creat_BiTree(str, n, A);
			else
			T->lchild = NULL;
			if (A + 1 <= n)
				T->rchild = Creat_BiTree(str, n, A + 1);
			else
			T->rchild = NULL;
		}
		return T;
}
//����������ǵݹ飩
void NRpOrder(BiTree T)
{
	BiTree stack[1024],p;
	int top = -1;
	if (T == NULL) return;
	p = T;
	while (!(p == NULL && top == -1))
	{
		while (p)
		{
			printf("%c",p->data);
			top++;
			stack[top] = p;
			p = p->lchild;
		}
			p = stack[top];
			top--;
			p = p->rchild;
	}
}
//������������
void Change_child(BiTree T)
{
	BiTree stack[1024], p,temp;
	int top = -1;
	if (T == NULL) return;
	p = T;
	while (!(p == NULL && top == -1))
	{
		while (p)
		{
			top++;
			stack[top] = p;
			p = p->lchild;
		}
		p = stack[top];
		top--;
		p = p->rchild;
		temp = stack[top+1]->lchild;
		stack[top+1]->lchild = stack[top+1]->rchild;
		stack[top+1]->rchild = temp;
	}
}
//���ƶ�����
BiThrTree Copy_BiTree(BiTree T)
{
	BiThrTree T2=NULL;
	if (T)
	{
		T2 = (BiThrTree)malloc(sizeof(BiThrNodeType));
		if (T2)
		{
			T2->data = T->data;
			T2->lchild= Copy_BiTree(T->lchild);
			T2->rchild= Copy_BiTree(T->rchild);
		}
	}
	return T2;
}
//������������
BiThrTree InOrderThr(BiThrTree p)
{
	BiThrTree head;
	head = (BiThrNodeType*)malloc(sizeof(BiThrNodeType));
	if (head)
	{
		head->ltag = 0;
		head->rtag = 1;
		head->rchild = head;
		if (!p)
			head->lchild = head;
		else
		{
			head->lchild = p;
			p = head;
			InThreading(p);
			p->rchild = head;
			p->rtag = 1;
			head->rchild = p;
		}
		return head;
	}
}
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);
		if (p->lchild == NULL)
		{
			p->ltag = 1;
			p->lchild = p;
		}
		if (p->rchild == NULL)
		{
			p->rtag = 1;
			p->rchild = p;
		}
		p = p;
		InThreading(p->rchild);
	}
}
//T2�����������飩
void p_orders(BiThrTree T2)
{
	if (T2)
	{
		printf("%c", T2->data);
		p_orders(T2->lchild);
		p_orders(T2->rchild);
	}
}
void P(BiTree T)
{
	BiTree temp;
	if (T == NULL)
		return;
	else
	{
		Change_child(T->lchild);
		Change_child(T->rchild);
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
	}
}