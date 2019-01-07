#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *StrDelete(char *S, int i, int m)
//这里的第一个位置i指的是数组的还是顺序的？
{ //这里指数组，i>=0
    char *p;
    char c[1];
    if (i >= strlen(S) || i < 0)
        return S;
    if (!(p = strdup(S)))
        return 0; //拷贝失败
    if (i + m >= strlen(S))
        strcpy(S + i, c);
    else
        strcpy(strcpy(S + i, c), p + i + m);
    free(p);
    return S;
}
int main(int argc, char const *argv[])
{

    char S[100];
    char T[] = "ABCDEFG";
    int i;
    strcpy(S, T);
    for (i = -5; i < 15; i++)
        printf("%s\n", StrDelete(S, i, 2));
    return 0;
}
