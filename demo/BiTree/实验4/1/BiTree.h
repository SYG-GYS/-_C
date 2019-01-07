#ifndef __BITREE_H
#define __BITREE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct BiNode
{
	char data;
	struct BiNode *lchild, *rchild;
}BiNode, *BiTree;
typedef struct
{
	BiTree data[1024];
	int top;
}SeqStack,*Stack;

BiTree Creat_BiTree();                                     //创建二叉树
void In_order(BiTree T);                                   //先序遍历
void Pre_order(BiTree T);                                  //中序遍历
void Post_order(BiTree T);                                 //后序遍历
int Sreach(BiTree T, char X,Stack S);                      //寻找X
void Action (BiTree T, char X, Stack S);                   //指定操作
void InsertL(BiTree T, char x,Stack S);                    //插入元素
void DeleteL(BiTree T);                                    //删除X的子树
void Delete(BiTree T);
int Lsum_BiTree(BiTree T);                                 //二叉树叶子数
int Sum_BiTree(BiTree T);                                  //二叉树结点数
int High_BiTree(BiTree T);                                 //二叉树高度

#endif