#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
//4．采用顺序存储结构存储串，编写一个函数计算一个子串在一个字符串中出现的次数，如果该子串不出现则为0。
int StrCount(char *str1, char *str2)
{
	int s1_len = strlen(str1), s2_len = strlen(str2), temp=0;
	int i, j, k = 0;
	char *p;
	static int count = 0;
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
		for (k = 0; k <= s1_len; k++)
		{
			if (str1[k] == str2[j])
				j++;
			else if (j - i == s1_len)
			{
				count++;//计数
				//i = i + s1_len;//提高效率  
			}
			if (str1[k] == '\0' && j - i == s1_len + 1)//处理特殊字符串尾‘\0’ 
				count++;
		}
	}
	return count;
}
int main()
{
	char str1[] = "bcabcabcabc";//question:这个样子是属于2个，还是一个？
	char str2[] = "abcabc";
	printf("%d\n", StrCount(str1, str2));
	return 0;
}

