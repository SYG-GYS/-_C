#include "LinkList.h"

int main(int argc, char const *argv[])
{
    DLinkList DL;
    DLNode *p;
    int i, DL_case, temp;
    datatype_LinkList x;
    while (1)
    {
        printf("请选择操作：1.建立双向链表2.插入3.删除_按序号4.查找_按值5.退出:");
        scanf("%d", &DL_case);
        switch (DL_case)
        {
        case 1:
            DL = Creat_DLinkList_2();
            Print_DLinkList(DL);
            break;
        case 2:
            printf("选择插入[序号][值]");
            scanf("%d %d", &i, &x);
            temp = Insert_DLinkList(DL, i, x);
            if (temp)
                Print_DLinkList(DL);
            else
                printf("抱歉，插入失败/n");
            break;
        case 3:
            printf("选择删除[序号]");
            scanf("%d ", &i);
            temp = Del_DLinkList(DL, i);
            if (temp)
                Print_DLinkList(DL);
            else
                printf("抱歉，删除失败/n");
            break;
        case 4:
        printf("输入查找的值：");
            scanf("%d0", &x);
            Locate_DLinkList(DL, x);
            break;
        case 5:
            exit(0);
            // break;
        default:
            printf("输入超出选择\n");
            break;
        }
    }
}
