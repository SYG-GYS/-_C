#include "LinkList.h"

int main(int argc, char const *argv[])
{
    LinkList L = NULL; //定义链表L为空
    LNode *s;
    int x; 
        s = (LNode *)malloc(sizeof(LNode));
       // s->data = x; //申请节点，赋值数据
        printf("%d\n",s->next);
        L= s->next;
        
        printf("%d",NULL);
    
    return 0;
}
