#ifndef __SEQUEUE_H
#define __SEQUEUE_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAXSIZE 1024
#define datatype int

typedef struct
{
    datatype data[MAXSIZE];                //数据的存储区
    int rear, front;                       //队头队尾指针
    int num;                               //队中元素的个数
} CSeQueue;                                //循环队
CSeQueue *Init_SeQueue(void);              //构造一个空的循环队
int In_SeQueue(CSeQueue *q, datatype x);   //循环队入队
int Out_SeQueue(CSeQueue *q, datatype *x); //循环队出队
int Empty_SeQueue(CSeQueue *q);            //判断循环队空队
#endif
