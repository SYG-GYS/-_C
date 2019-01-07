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

BiTree Creat_BiTree(char str[], int n,int A);          //创建二叉树
void NRPreOrder(BiTree T);                             //先序遍历（非递归）
void Change_child(BiTree T);                           //交换左右子树
BiThrTree Copy_BiTree(BiTree T);                       //复制二叉树至T2  
BiThrTree InOrderThr(BiThrTree T);                     //线索化二叉树T2
void InThreading(BiThrTree p);
void Pre_orders(BiThrTree T2);                         //T2先序遍历（检查）

#endif

