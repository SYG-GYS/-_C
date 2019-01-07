#include "SeQueue.h"

CSeQueue *Init_SeQueue(void)
{
    CSeQueue *q;
    q = (CSeQueue *)malloc(sizeof(CSeQueue));
    q->front = q->rear = MAXSIZE - 1;
    q->num = 0;
    return q;
}
int In_SeQueue(CSeQueue *q, datatype x)
{
    if (q->num == MAXSIZE)
    {
        printf("");
        return -1;
    }
    else
    {
        q->rear = (q->rear + 1) % MAXSIZE;
        q->data[q->rear] = x;
        q->num++;
        return 1;
    }
}
int Out_SeQueue(CSeQueue *q, datatype *x)
{
    if (q->num == 0)
    {
        printf("");
        return -1;
    }
    else
    {
        q->front = (q->front + 1) % MAXSIZE;
        *x = q->data[q->front];
        q->num--;
        return 1;
    }
}
int Empty_SeQueue(CSeQueue *q)
{
    if (q->num == 0)
        return 1;
    else
        return 0;
}