#include <string.h>
#include <stdio.h>

int main()
{
int i,j;
for (i=10;i>0;i--)
    for(j=10;j>0;j--)
    {
        if(i>5||j<3)
            continue;
        else
            printf("i %d,j %d\n",i,j);
    }
}



// if(s2_len>=s1_len)
// ;
// else
// {
//     p=str1;
//     str1=str2;
//     str2=p;
// }


