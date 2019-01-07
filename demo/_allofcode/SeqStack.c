#include "SeqStack.h"
#define L 100
SeqStack *Init_SeqStack(void)
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack)); //申请栈的空间
    s->top = -1;                              //初始化栈顶指针
    return s;
}
int Empty_SeqStack(SeqStack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int Push_SeqStack(SeqStack *s, SeqStack_datatype x)
{
    if (s->top == MAXSIZE - 1) //栈满，不能入栈
        return 0;
    else
    {
        s->top++;
        s->data[s->top] = x;
        return 1;
    }
}
int Pop_SeqStack(SeqStack *s, SeqStack_datatype *x)
{
    if (Empty_SeqStack(s)) //栈空，不能出栈
        return 0;
    else
    {
        *x = s->data[s->top];
        s->top--; //更新栈顶指针
        return 1;
    } //栈顶元素存入*x,返回
}
int Top_SeqStack(SeqStack *s, SeqStack_datatype *x)
{
    if (Empty_SeqStack(s)) //栈空，无元素
        return 0;
    else
    {
        *x = s->data[s->top];
        return 1;
    }
}

void conversion_basic(int N, int r)
{
    SeqStack *s;
    SeqStack_datatype x;
    s = Init_SeqStack();
    while (N != 0)
    {
        Push_SeqStack(s, N % r);
        N = N / r;
    }
    while (!Empty_SeqStack(s))
    {
        Pop_SeqStack(s, &x);
        printf("%d", x);
    }
}
void conversion_user_defined(int N, int r)
{
    int top;
    int s[L]; //定义一个顺序栈
    int x;
    top = -1; //初始化栈
    while (N != 0)
    {
        s[++top] = N % r; //余数入栈
        N = N / r;        //商作为被除数继续
    }
    while (top != -1)
    {
        x = s[top--];
        printf("%d", x);
    }
}
void print_SeqStack(SeqStack *s)
{
    SeqStack_datatype x;
    int temp;
    temp = s->top;
    if (s->top == -1)
    {
        printf("空栈，无效请求");
    }
    else
    {
        while (s->top != -1)
        {
            x = s->data[s->top];
            printf("%d ", x);
            s->top--;
        }
        while (temp > s->top)
            s->top++;
    }
    printf("\n");
}