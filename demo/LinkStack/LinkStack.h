#ifndef __LINKSTACK_H
#define __LINKSTACK_H
#define datatype int

//链栈
typedef struct snode
{
    datatype data;
    struct snode *next;
} StackNode, *LinkStack;

//置空栈
int Empty_LinkStack(LinkStack top);                  //判空栈
LinkStack Push_LinkStack(LinkStack top, datatype x); //入栈
LinkStack Pop_LinkStack(LinkStack top, datatype *x); //出栈
#endif