#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strInsert(char *S, const char *T, int i)
{
    char *buf;
    if (i < 0 || i > strlen(S))
        return S;
    if (!(buf = strdup(S)))
        return 0;
    strcat(strcpy(S + i, T), buf + i);
    free(buf);
    return S;
}
int main(void)
{
    char S[100];
    char T[] = "ABCDEFG";
    int i;
    for (i = -5; i <= 15; i++)
    {
        strcpy(S, "0123456789");
        printf("i=%3d: [%s]\n", i, strInsert(S, T, i));
    }
    return 0;
}