#ifndef __SEQLIST_H
#define __SEQLIST_H
#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 32   //数据最多可存32个
typedef int Seqdata; //这里我们定义 顺序表的数据 为 int

typedef struct
{
	Seqdata data[MAXSIZE];
	int last;
} SeqList;

//顺序表初始化
SeqList *init_SeqList();
//顺序表的插入
int Insert_SeqList(SeqList *L, int i, Seqdata x);
//顺序表的删除
int Delete_SeqList(SeqList *L, int i);
//顺序表的按值查找
int Location_SeqList(SeqList *L, Seqdata x);
//划分算法
void part(SeqList *L);
//顺序表的合并（不在实验一要求中）
void merge(SeqList *A, SeqList *B, SeqList *C);
//顺序表的比较
int compare(int A[], int B[], int m, int n);

#endif