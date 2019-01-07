#include <malloc.h>
#include <stddef.h>
#include "LinkStack.h"
//链栈
/* typedef struct snode{
    datatype data;
    struct snode *next;
}StackNode,*LinkStack; */

//置空栈,未写
int Empty_LinkStack(LinkStack top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
LinkStack Push_LinkStack(LinkStack top, datatype x)
{
    StackNode *p;
    p = (StackNode *)malloc(sizeof(StackNode));
    p->data = x;
    p->next = top;
    top = p;
    return top;
}
LinkStack Pop_LinkStack(LinkStack top, datatype *x)
{
    StackNode *p;
    if (top == NULL)
        return NULL;
    else
    {
        *x = top->data;
        p = top;
        top = top->next;
        free(p);
        return top;
    }
}