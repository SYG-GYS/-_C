#ifndef __BITREE_H
#define __BITREE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct BiNode
{
	char data;
	struct BiNode *lchild, *rchild;
}BiNode, *BiTree;
typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	unsigned ltag;
	unsigned rtag;
}BiThrNodeType,*BiThrTree;

BiTree Creat_BiTree(char str[], int n,int A);          //����������
void NRPreOrder(BiTree T);                             //����������ǵݹ飩
void Change_child(BiTree T);                           //������������
BiThrTree Copy_BiTree(BiTree T);                       //���ƶ�������T2  
BiThrTree InOrderThr(BiThrTree T);                     //������������T2
void InThreading(BiThrTree p);
void Pre_orders(BiThrTree T2);                         //T2�����������飩

#endif

