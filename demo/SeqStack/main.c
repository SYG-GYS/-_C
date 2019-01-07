#include "SeqStack.h"

int main(int argc, char const *argv[])
{7
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
