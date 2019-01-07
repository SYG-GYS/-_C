#include "LinkList.h"

int main(int argc, char const *argv[])
{
    /* 获得已知 单链表*/
    LinkList L;
    LNode *p;
    int x,_temp;
    printf("请按顺序输入插件单链表的元素 [结束标志：0]\n");
    L = Creat_LinkList_1_2();
    print_LinkList_2(L);
    printf("请输入要查找x的值:");
    scanf("%d0", &x);   //%d不加0，需要重复输入2次；加0后，只需输入1次。可能跟键盘缓冲区有关，scanf在缓冲区有字符时结束输入。
    //以下代码有问题
    printf("x的结点个数:");
    _temp = count_LinkList(L,x);
    printf("%d",_temp);
    return 0;
}
