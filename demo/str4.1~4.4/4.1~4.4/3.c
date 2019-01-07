#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
//采用顺序结构存储串，编写一个函数，求串和串的一个最长的公共子串
char *StrSubMax(char *str1, char *str2)
{
	int s1_len = strlen(str1), s2_len = strlen(str2), temp;
	int i, j, k = 0;
	int max_right = 0, max_left = 0;//定位
	char *p;
	static char str[100];
	if (s2_len < s1_len) //str2被比较串，str1样本串 
	{
		p = str1;
		str1 = str2;
		str2 = p;
		temp = s1_len;
		s1_len = s2_len;
		s2_len = temp;
	} //始终保持 str2 为最大

	for (i = 0; i < s2_len; i++) //str2比较开始的位置
	{
		j = i;
		for (k = 0; k <= s1_len; k++) //与str1逐个比较
		{//判断条件注意是否存在样本串可以完全匹配的情况
			if (str1[k] == str2[j])
				j++;
			else if (str1[k] != str2[j])
			{
				if (j - i > max_right - max_left)
				{
					max_left = i;
					max_right = j;
				}
				break;
			}
		}
	}
	k = 0;
	for (; max_left < max_right; max_left++)
	{
		str[k] = str2[max_left];
		k++;
	}
	return str;
}
int main(int argc, char const *argv[])
{
	char str1[] = "asdsdasabcssd";
	char str2[] = "abc";
	printf("%s\n", StrSubMax(str1, str2));
	return 0;
}
