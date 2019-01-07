#include "LinkList.h"

int main(int argc, char const *argv[])
{
    int OK = 0, i, x;
    int _case;
    // char flag_main = '0';   //以0标志结束    //修改于LinkList.c
    LinkList L = NULL; //建立空结构体指针
    LNode *p;
    printf("请选择，并输入序号\n");
    while (1)
    {
        printf("    1.头插法建立单链表2.插入3.删除4.查找5.退出\nyour choice:");
        scanf("%d", &_case);
        switch (_case)
        {
        case 1:
            printf("请按顺序输入插件单链表的元素 [结束标志：0]\n");
            L = Creat_LinkList_1(); //建立单链表,表头_插入
            print_LinkList(L);
            //printf("%d", Length_LinkList_1( L))  ;
            break;
        case 2:
            printf("请问，你想在哪个节点插入：[序号 插入值]\n");
            scanf("%d%d", &i, &x);
            Insert_LinkList(L, i, x); //单链表的插入
            print_LinkList(L);
            break;
        case 3:
            printf("请问，你想删除哪个节点：[序号]\n");
            scanf("%d", &i);
            Del_LinkList(L, i);
            print_LinkList(L);
            break;
        case 4:
            printf("请问，你想查找哪个节点：[序号]\n");
            scanf("%d", &i);
            p = Get_LinkList(L, i);
            if (p)
                printf("i:%d data:%d\n", i, (*p).data);
            break;
        case 5:
            exit(0);
        //    break;
        default:
            printf("输入序号错误，请选择重新输入\n");
            break;
        }
    }

    //     scanf("请问，你想删除哪个节点：%d", &i);
    //     OK =Del_LinkList(L, i); //单链表的删除
    // /*     if (OK)
    //         printf("成功删除"); */
    //     scanf("请问，你想查找哪个节点：%d", &i);
    //     p = Get_LinkList( L,i); //单链表的查找__按序号
    //     printf("%d",&p);
    return 0;
}