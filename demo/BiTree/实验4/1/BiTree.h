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

BiTree Creat_BiTree();                                     //����������
void In_order(BiTree T);                                   //�������
void Pre_order(BiTree T);                                  //�������
void Post_order(BiTree T);                                 //�������
int Sreach(BiTree T, char X,Stack S);                      //Ѱ��X
void Action (BiTree T, char X, Stack S);                   //ָ������
void InsertL(BiTree T, char x,Stack S);                    //����Ԫ��
void DeleteL(BiTree T);                                    //ɾ��X������
void Delete(BiTree T);
int Lsum_BiTree(BiTree T);                                 //������Ҷ����
int Sum_BiTree(BiTree T);                                  //�����������
int High_BiTree(BiTree T);                                 //�������߶�

#endif