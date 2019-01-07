#include "LQueue.h"

LQueue *Init_LQueue(void)
{
    LQueue *q;
    QNode *p;
    q = (LQueue *)malloc(sizeof(LQueue)); //申请头尾指针节点
    p = (QNode *)malloc(sizeof(QNode));   //申请链队头结点
    p->next = NULL;
    q->front = p;
    q->rear = p;
    return q;
}
void In_LQueue(LQueue *q, datatype x)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    p->data = x;//头结点赋值
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}
int Empty_LQueue(LQueue *q)
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}
int Out_LQueue(LQueue *q, datatype *x)
{
    QNode *p;
    if (Empty_LQueue(q))
    {
        printf("队空");
        return 0; //队空，出队失败
    }
    else
    {
        p = q->front->next;
        q->front->next = p->next;
        *x = p->data; //队头元素放x中
        free(p);
        // if (q->front->next = NULL)//只有一个元素时，出队后队空，此时还要修改队尾指针
        //     q->rear = q->front;
        return 1;
    }
}
void print_LQueue(LQueue *q)
{

    QNode *p;
    p = q->front->next;
    printf("print_LQueue:");
    // L = L->rear;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}
int input_LQueue(LQueue *q)
{
    datatype x;
    printf("请输入元素：");
    scanf("%d",&x);
    while(x!=flag)
    {
        
        In_LQueue(q,x);
        scanf("%d",&x);
    }
    return 1;
}