#ifndef __SEQSTACK_H
#define __SEQSTACK_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SeqStack_datatype int
//顺序栈
#define MAXSIZE 1024
typedef struct
{
    SeqStack_datatype data[MAXSIZE];
    int top;
} SeqStack;

SeqStack *Init_SeqStack(void);                       //置空栈
int Empty_SeqStack(SeqStack *s);                     //判空栈
int Push_SeqStack(SeqStack *s, SeqStack_datatype x); //入栈
int Pop_SeqStack(SeqStack *s, SeqStack_datatype *x); //出栈
int Top_SeqStack(SeqStack *s, SeqStack_datatype *x); //取栈顶元素
void conversion_basic(int N, int r);                 //十进制转r进制
void conversion_user_defined(int N, int r);          //十进制转r进制
void print_SeqStack(SeqStack *s);                    //打印栈表
#endif