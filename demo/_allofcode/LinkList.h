#ifndef __LINKLIST_H
#define __LINKLIST_H
#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"

#define datatype_LinkList int

typedef struct lnode
{ //单链表节点的定义
    datatype_LinkList data;
    struct lnode *next;
} LNode, *LinkList;

typedef struct dlnode
{ //双向链表的定义
    datatype_LinkList data;
    struct dlnode *prior, *next;
} DLNode, *DLinkList;

//单链表操作
LinkList Creat_LinkList_1(void);                    //建立单链表，表头_插入
LinkList Creat_LinkList_2(void);                    //建立单链表，表尾_插入
int Length_LinkList_1(LinkList L);                  //计算单链表_1_表长
int Length_LinkList_2(LinkList L);                  //计算单链表_2_表长
LNode *Get_LinkList(LinkList L, int i);             //单链表的查找__按序号
LNode *Locate_LinkList(LinkList L, datatype_LinkList x);     //单链表的查找__按值
int Insert_LinkList(LinkList L, int i, datatype_LinkList x); //单链表的插入
int Del_LinkList(LinkList L, int i);                //单链表的删除
void reverse_LinkList(LinkList H);                  //单链表逆置
void pur_LinkList(LinkList H);                      //单链表中删除重复节点
LinkList merge_LinkList(LinkList A, LinkList B);    //单链表的合并
// LinkList Circular_LinkList(LinkList L1, LinkList L2); //将两个单链表合成循环链表
void print_LinkList(LinkList L);            //打印单链表
void print_LinkList_2(LinkList L);          //打印单链表_无头结点
LinkList Creat_LinkList_1_2(void);          //建立单链表，表头_插入_无头结点
int count_LinkList(LinkList L, datatype_LinkList x); //计算同值元素个数
//双向链表操作
DLinkList Creat_DLinkList(LinkList L);                //单链表转换为双向循环链表
DLinkList Creat_DLinkList_2(void);                    //建立双向链表,表尾_插入
void Print_DLinkList(DLinkList L);                    //打印双向链表
int Insert_DLinkList(DLinkList L, int i, datatype_LinkList x); //双向链表插入
int Del_DLinkList(DLinkList L, int i);                //双向链表删除_按序号
int Locate_DLinkList(DLinkList L, datatype_LinkList x);    //双向链表查找_按值


#endif