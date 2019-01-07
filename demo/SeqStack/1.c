#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct
{
    int data[MAXSIZE];
    int top;
} SqStack;
void PushStack(SqStack *S, int x) //入栈
{
    if (S->top == MAXSIZE - 1)
        printf("栈已满，不能入栈！\n");
    else
    {
        S->data[++S->top] = x;
        printf("入栈已完成！\n");
    }
}
void PopStack(SqStack *S) //退栈
{
    if (S->top == -1)
        printf("栈为空，不能出栈！\n");
    else
    {
        S->top--;
        printf("退栈已完成！\n");
    }
}
int GetStackTop(SqStack S) //取栈顶元素
{
    return S.data[S.top];
}

int main()
{
    int x, i;
    SqStack myStack;
    myStack.top = -1;
    do
    {
        printf("请选择你需要的操作:1.置空栈2.进栈3.退栈4.取栈顶元素5.退出程序.\n(请输入1或2或3或4或5):");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            myStack.top = -1;
            printf("栈已置空！\n");
            break;
        case 2:
            printf("请输入你要进栈的元素：");
            scanf("%d", &x);
            PushStack(&myStack, x);
            break;
        case 3:
            PopStack(&myStack);
            break;
        case 4:
            if (myStack.top != -1)
                printf("栈顶元素是 %d.\n", GetStackTop(myStack));
            else
                printf("栈为空，没有元素！\n");
            break;
        case 5:
            break;
        default:
            printf("选择错误，请重新输入！\n");
            break;
        }
    } while (i != 5);
    return 0;
}

// //链栈>>>>>>>>>>>>
// #include <stdio.h>
// #include <stdlib.h>
// typedef struct SNode
// {
//     int data;
//     struct SNode *next;
// } SNode, *LinkStack;
// LinkStack top;
// LinkStack PushStack(LinkStack top, int x) //入栈
// {
//     LinkStack s;
//     s = (LinkStack)malloc(sizeof(SNode));
//     s->data = x;
//     s->next = top;
//     top = s;
//     return top;
// }
// LinkStack PopStack(LinkStack top) //退栈
// {
//     LinkStack p;
//     if (top != NULL)
//     {
//         p = top;
//         top = top->next;
//         free(p);
//         printf("退栈已完成\n");
//         return top;
//     }
//     else
//         printf("栈是空的，无法退栈！\n");
//     return 0;
// }
// int GetStackTop(LinkStack top) //取栈顶元素
// {
//     return top->data;
// }
// main()
// {
//     int i, x;
//     do
//     {
//         printf("请选择你需要的操作：\n1.置空栈.\n2.进栈.\n3.退栈.\n4.取栈顶元素.\n5.退出程序.\n(请输入1或2或3或4或5):");
//         scanf("%d", &i);
//         switch (i)
//         {
//         case 1:
//             top = NULL;
//             break;
//         case 2:
//             printf("请输入你要进栈的元素：");
//             scanf("%d", &x);
//             top = PushStack(top, x);
//             printf("进栈已完成！\n");
//             break;
//         case 3:
//             top = PopStack(top);
//             break;
//         case 4:
//             if (top != NULL)
//                 printf("栈顶元素是：%d!\n", GetStackTop(top));
//             else
//                 printf("栈是空的，没有元素！\n");
//             break;
//         case 5:
//             break;
//         default:
//             printf("选择错误，请重新输入！\n");
//             break;
//         }
//     } while (i != 5);
//     return 0;
// }