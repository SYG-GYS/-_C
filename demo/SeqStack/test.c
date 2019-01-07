#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SeqStack_datatype int
#define MAXSIZE 1024
#define L 100

typedef struct
{
    SeqStack_datatype data[MAXSIZE];
    int top;
} SeqStack;

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

int main(int argc, char const *argv[])
{
    SeqStack *s;
    SeqStack_datatype x;
    int _case, flag, i = 0;
    int N, r; //数制转化用参数
    s = Init_SeqStack();
    while (1)
    {
        printf("请选择操作：1.置空栈2.入栈3.出栈4.取栈顶元素5.十进制转r进制6.打印栈表，从栈顶开始7.退出");
        scanf("%d", &_case);
        switch (_case)
        {
        case 1:
            s = Init_SeqStack();
            printf("置空栈完成");
            break;
        case 2:
            printf("入栈元素：");
            scanf("%d", &x); //scanf()函数是真的神奇，不知道scanf()真正的用法啊
            Push_SeqStack(s, x);
            break;
        case 3:
            Pop_SeqStack(s, &x);
            printf("i:%d %d\n", ++i, x);
            printf("剩余元素：");
            print_SeqStack(s);//打印栈表，从栈顶开始
            break;
        case 4:
            Top_SeqStack(s, &x);
            printf("Top:%d\n", x);
            break;
        case 5:
            printf("请输入N r:");
            scanf("%d%d", &N, &r);
            conversion_user_defined(N, r);
            putchar('\n');
            break;
        case 6:
            printf("打印栈表:");
            print_SeqStack(s);//打印栈表，从栈顶开始
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("选择错误，请重新选择\n");
            break;
        }
    }
    return 0;
}
