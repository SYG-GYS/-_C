#ifndef __LQUEUE_H
#define __LQUEUE_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define datatype int
#define flag -1
typedef struct node
{
    datatype data;
    struct node *next;
} QNode; //链队节点的类型
typedef struct
{
    QNode *front, *rear;
} LQueue; //将头尾指针封装在一起的链队

LQueue *Init_LQueue(void);              //置一个空链队_带头结点
void In_LQueue(LQueue *q, datatype x);  //链队入队
int Empty_LQueue(LQueue *q);            //链队判空
int Out_LQueue(LQueue *q, datatype *x); //链队出队
void print_LQueue(LQueue *q);           //链队打印
int input_LQueue(LQueue *q);            //输入元素
#endif
