#include "LinkList.h"
// #include <windows.h> //以下代码 以单下划线为开头的定义变量为临时使用
#define flag 0 //flag为根据具体情况设置的结束输入的标志
int DL_i;
/* typedef struct londe{
    datatype_LinkList data;
    struct londe *next;
} LNode,*LinkList; */
// struct tag { member-list } variable-list ;
LinkList Creat_LinkList_1(void)
{
    LinkList L = NULL; //定义链表L为空
    LNode *s;
    int x; //设定输入数据元素为int型
    scanf("%d", &x);
    while (x != flag)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x; //申请节点，赋值数据
        s->next = L;
        L = s; //将节点s插入到链表头部
        scanf("%d", &x);
    }
    s = (LNode *)malloc(sizeof(LNode)); //添加头结点
    // s->data = NULL;
    s->next = L;
    L = s;
    return L;
}
LinkList Creat_LinkList_2(void)
{
    LinkList L = NULL; //定义链表L为空
    LNode *s, *r = NULL;
    int x; //设定输入数据元素为int型
    scanf("%d", &x);
    while (x != flag)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        if (L == NULL) //第一个节点的处理
            L = s;
        else //其他节点的处理
            r->next = s;
        r = s; //r指向新的尾节点
        scanf("%d", &x);
    }
    if (r != NULL)
        r->next = NULL; //对于非空表，最后节点的指针域置空
    return L;
}
int Length_LinkList_1(LinkList L)
{
    LNode *p = L; //p指向头结点
    int j = 0;
    while (p->next)
    {
        p = p->next; //p指向的是第j个节点
        j++;
    }
    return j;
}
int Length_LinkList_2(LinkList L)
{
    LNode *p = L; //非空表情况下，p所指的是第一个节点
    int j = 0;
    while (p)
    {
        j++;
        p = p->next;
    }
    return j;
}
LNode *Get_LinkList(LinkList L, int i)
{ //在单链表L中查找第i个元素节点，找到返回其指针，否则返回空
    //    LNode *p = L;
    LinkList p = L;
    int j = 0;
    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (j == i)
        return p;
    else
        return NULL;
}
LNode *Locate_LinkList(LinkList L, datatype_LinkList x) //only could find the frist x
{                                                       //在单链表L中查找值为x的元素节点，找到返回其指针，否则返回空
    LNode *p = L->next;
    while (p != NULL && p->data != x)
        p->next;
    return p;
}
int Insert_LinkList(LinkList L, int i, datatype_LinkList x)
{ //在单链表L的第i个位置上插入值为x的元素
    // LNode *p, *s;
    LinkList p, s;
    p = Get_LinkList(L, i - 1); //查找的i-1个节点
    if (p == NULL)              //不存在第i-1个节点，无法插入
    {
        printf("参数i错误");
        return 0;
    }
    else
    {
        s = (LNode *)malloc(sizeof(LNode)); //申请，填装节点
        s->data = x;
        s->next = p->next; //新节点插入在第i-1个节点的后面
        p->next = s;
        return 1;
    }
}
int Del_LinkList(LinkList L, int i)
{ //删除单链表L上的第i个节点
    LinkList p, s;
    p = Get_LinkList(L, i - 1);
    if (p == NULL)
    {
        printf("第i-1个节点不存在");
        return -1;
    }
    else if (p->next == NULL)
    {
        printf("第i个节点不存在");
        return 0;
    }
    else
    {
        s = p->next;       //s指向第i个节点
        p->next = s->next; //从链表中删除
        free(s);           //释放*s
        return 1;
    }
}
void reverse_LinkList(LinkList H)
{
    LNode *p;
    LNode *q;       /* temp variable quantity */
    p = H->next;    //p指向第一个数据节点
    H->next = NULL; //将原链表置为空表H
    while (p)
    {
        q = p;
        p = p->next;
        q->next = H->next; //将当前节点插入到头结点的后面
        H->next = q;
    }
}
void pur_LinkList(LinkList H)
{
    LNode *p, *q, *r;
    p = H->next; //p指向第一个节点
    if (p == NULL)
        return;
    while (p->next)
    {
        q = p;          //从*p的后继开始找重复节点
        while (q->next) //
        {
            if (q->next->data == p->data)
            { //找到重复节点，用r指向，删除*r
                r = q->next;
                q->next = r->next;
                free(r);
            }
            else
                q = q->next;
        }            /*while(q->next)*/
        p = p->next; //p指向下一个，继续
    }                /*while(p-next)*/
}
LinkList merge_LinkList(LinkList A, LinkList B) /* 设A，B均为带__头结点的__单链表 */
{
    LinkList C;
    LNode *p, *q;
    LNode *s; /* temp variable quantity */
    p = A->next;
    q = B->next;
    C = A; //C表的头结点
    C->next = NULL;
    free(B);
    while (p && q)
    {
        if (p->data < q->data)
        {
            s = p;
            p = p->next;
        }
        else
        { //从原A、B表上摘下较小者
            s = q;
            q = q->next;
        }
        s->next = C->next; //插入到C表的头部
        C->next = s;
    }
    if (p == NULL)
    {
        p = q;
    }
    while (p) //将剩余的节点一个一个摘下，插入到C表的头部
    {
        s = p;
        p = p->next;
        s->next = C->next;
        C->next = s;
    }
}
/* LinkList Circular_LinkList(LinkList L1,LinkList L2){
} */
void print_LinkList(LinkList L)
{
    //LinkList p = L;
    LNode *p = L;
    p = p->next; //指针从头结点指向第一个节点
    printf("print_LinkList:");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}
void print_LinkList_2(LinkList L)
{
    //LinkList p = L;
    LNode *p = L;
    //p=p->next;  //指针从头结点指向第一个节点
    printf("print_LinkList:");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}
LinkList Creat_LinkList_1_2(void)
{
    LinkList L = NULL; //定义链表L为空
    LNode *s;
    int x; //设定输入数据元素为int型
    scanf("%d", &x);
    while (x != flag)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x; //申请节点，赋值数据
        s->next = L;
        L = s; //将节点s插入到链表头部
        scanf("%d", &x);
    }
    /*     s = (LNode *)malloc(sizeof(LNode)); //添加头结点
    s->data = NULL;
    s->next = L;
    L = s; */
    return L;
}
int count_LinkList(LinkList L, datatype_LinkList x)
{
    LNode *p;
    int _count = 0;
    p = L;
    while (p != NULL)
    {
        if (p->data == x)
            _count++;
        // printf("%d ", p->data);
        p = p->next;
    }
    return _count;
}

//双向链表操作
DLinkList Creat_DLinkList(LinkList L)
{
    DLinkList H;
    DLNode *rear, *s;
    LNode *p;
    H = (DLNode *)malloc(sizeof(DLNode)); //生成H的头结点
    H->next = H;
    H->prior = H; //将H构造为空的双向循环链表
    rear = H;     //rear为尾指针
    p = L->next;  //p指向L的第一个元素
    while (p)
    {
        s = (DLNode *)malloc(sizeof(DLNode)); //申请，填装节点s
        s->data = p->data;                    //接收L的数据
        s->next = rear->next;
        s->prior = rear;
        rear->next = s;
        H->prior = s; //节点s插入到H的链表尾
        rear = s;     //修改H的尾指针
        p = p->next;
    }
    return H;
}
DLinkList Creat_DLinkList_2(void) //建立双向链表,表尾_插入
{
    DLinkList H = NULL;
    DLNode *r, *s;
    int x, i = 0;
    //int DL_i;                             //全局变量
    H = (DLNode *)malloc(sizeof(DLNode)); //生成H的头结点
    H->next = H;
    H->prior = H; //将H构造为空的双向循环链表
    r = H;        //r为尾指针
    printf("请选择输入数据长度：");
    scanf("%d", &i);
    DL_i = i;
    if (i < 0)
    {
        printf("参数i错误");
        return NULL;
    }
    else if (i == 0)
    {
        printf("空表浪费内存，不建，━┳━　━┳━");
        return NULL;
    }
    else
    {
        printf("输入数据:");
        //scanf("%d\n", &x); //确保输入i>0后，scanf有效
        while (i)
        {
            scanf("%d0", &x);
            s = (DLNode *)malloc(sizeof(DLNode));
            s->data = x;
            s->next = r->next;
            r->next = s;
            H->prior = s; //节点s插入到H的链表尾
            r = s;        //修改H的尾指针
            i--;
        }
        //printf("test0");
        return H;
    }
}
void Print_DLinkList(DLinkList L)
{
    DLNode *p;
    p = L;
    p = p->next; //从头结点到第一个节点
    printf("DLinkList:");
    for (; p->next != L; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("%d \n", p->data); //循环需要补充一个尾部与头结点相邻的节点
}
int Insert_DLinkList(DLinkList L, int i, datatype_LinkList x)
{
    //int DL_i; //全局变量
    DLNode *p, *s;
    if (i < 1 || i > DL_i)
    {
        printf("插入参数i错误");
        return -1;
    }
    p = L;
    for (; i > 1; i--)
        p = p->next; //p移动到插入位置的指针
    s = (DLNode *)malloc(sizeof(DLNode));
    s->data = x;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    // //s插入到 p的前面____理解笔记
    // s->prior = p->prior; //p的前驱 移到 s的前驱
    // p->prior->next = s;  //s的地址 移到 p前驱对应的元素的后继
    // s->next = p;         //p的地址 移到 s的后继
    // p->prior = s;        //s的地址 移到 p的前驱
    DL_i++;
    return 1;
}
int Del_DLinkList(DLinkList L, int i)
{
    DLNode *p, *s;
    if (i < 1 || i > DL_i)
    {
        printf("插入参数i错误%d %d", i, DL_i);
        return -1;
    }
    p = L;
    for (; i > 1; i--)
        p = p->next; //p移动到插入位置-1的指针
    s = p->next;
    p->next = s->next;
    s->next->prior = p;
    free(p);
    //printf("DL_i %d ", DL_i);
    DL_i--;
    return 1;
}
int Locate_DLinkList(DLinkList L, datatype_LinkList x)
{
    DLNode *p;
    int i = 1;
    p = L;
    p = p->next; //从头结点到第一个节点
    while (p->next != L)
    {
        if (p->data == x)
            printf("i:%d ", i);
        p = p->next;
        i++;
    }
    if (p->data == x)
        printf("i:%d\n ", i);
    else
        printf("\n");
    return 0;
}
