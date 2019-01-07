#include "LQueue.h"
int main(int argc, char const *argv[])
{
    LQueue *q;
    //QNode *p;
    datatype x, _x1 = 0, _x2 = 0;
    int temp, _case;
    q = Init_LQueue();
    while (1)
    {
        printf("选择:1.建立链队_无头结点2.打印链队_正序3.连续删除2次4.连续入队3次5.退出\n");
        scanf("%d", &_case);
        switch (_case)
        {
        case 1:
        printf("请以-1作为结束符号");
            input_LQueue(q);
            break;
        case 2:
            print_LQueue(q);
            break;
        case 3:

            Out_LQueue(q, &_x1);
            Out_LQueue(q, &_x2);
            printf("出队：%d %d\n", _x1, _x2);
            print_LQueue(q);
            break;
        case 4:
            printf("键入3个元素");
            for (temp = 0; temp < 3; temp++)
            {
                scanf("%d", &x);
                In_LQueue(q, x);
            }
            print_LQueue(q);
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}