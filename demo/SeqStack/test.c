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
    s = (SeqStack *)malloc(sizeof(SeqStack)); //����ջ�Ŀռ�
    s->top = -1;                              //��ʼ��ջ��ָ��
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
    if (s->top == MAXSIZE - 1) //ջ����������ջ
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
    if (Empty_SeqStack(s)) //ջ�գ����ܳ�ջ
        return 0;
    else
    {
        *x = s->data[s->top];
        s->top--; //����ջ��ָ��
        return 1;
    } //ջ��Ԫ�ش���*x,����
}
int Top_SeqStack(SeqStack *s, SeqStack_datatype *x)
{
    if (Empty_SeqStack(s)) //ջ�գ���Ԫ��
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
    int s[L]; //����һ��˳��ջ
    int x;
    top = -1; //��ʼ��ջ
    while (N != 0)
    {
        s[++top] = N % r; //������ջ
        N = N / r;        //����Ϊ����������
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
        printf("��ջ����Ч����");
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
    int N, r; //����ת���ò���
    s = Init_SeqStack();
    while (1)
    {
        printf("��ѡ�������1.�ÿ�ջ2.��ջ3.��ջ4.ȡջ��Ԫ��5.ʮ����תr����6.��ӡջ����ջ����ʼ7.�˳�");
        scanf("%d", &_case);
        switch (_case)
        {
        case 1:
            s = Init_SeqStack();
            printf("�ÿ�ջ���");
            break;
        case 2:
            printf("��ջԪ�أ�");
            scanf("%d", &x); //scanf()������������棬��֪��scanf()�������÷���
            Push_SeqStack(s, x);
            break;
        case 3:
            Pop_SeqStack(s, &x);
            printf("i:%d %d\n", ++i, x);
            printf("ʣ��Ԫ�أ�");
            print_SeqStack(s);//��ӡջ����ջ����ʼ
            break;
        case 4:
            Top_SeqStack(s, &x);
            printf("Top:%d\n", x);
            break;
        case 5:
            printf("������N r:");
            scanf("%d%d", &N, &r);
            conversion_user_defined(N, r);
            putchar('\n');
            break;
        case 6:
            printf("��ӡջ��:");
            print_SeqStack(s);//��ӡջ����ջ����ʼ
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("ѡ�����������ѡ��\n");
            break;
        }
    }
    return 0;
}
