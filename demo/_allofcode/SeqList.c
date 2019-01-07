#include "SeqList.h"

//顺序表初始化
SeqList *init_SeqList()
{
	SeqList *L;
	L = (SeqList *)malloc(sizeof(SeqList));
	L->last = -1;
	return L;
}

//顺序表的插入
int Insert_SeqList(SeqList *L, int i, Seqdata x)
{
	int j;
	if (L->last == MAXSIZE - 1)
	{
		printf("表满"); //表空间已满，不能插入
		return -1;
	}
	if (i < 1 || i > L->last + 2) //检查插入位置的正确性
	{
		printf("位置错");
		return 0;
	}
	for (j = L->last; j >= i - 1; j--)
		L->data[j + 1] = L->data[j]; //结点移动
	L->data[i - 1] = x;				 //新元素插入
	L->last++;						 //last仍指向最后元素
	return 1;						 //插入成功，返回
}

//顺序表的删除
int Delete_SeqList(SeqList *L, int i)
{
	int j;
	if (i < 1 || i > L->last + 1) //检查空表及删除位置的合法性
	{
		printf("不存在第i个元素");
		return 0;
	}
	for (j = i; j <= L->last; j++)
		L->data[j - 1] = L->data[j]; //向上移动
	L->last--;
	return 1; //删除成功
}

//顺序表的按值查找
int Location_SeqList(SeqList *L, Seqdata x)
{
	int i = 0;
	while (i < L->last && L->data[i] != x)
		i++;
	if (i > L->last) //查找失败，返回的-1
		return -1;
	else
		return i; //查找成功，返回的是存储位置
}

//划分算法
void part(SeqList *L)
{
	int i, j;
	Seqdata x, y;
	x = L->data[0]; //将基准置入x中
	for (i = 1; i <= L->last; i++)
		if (L->data[i] < x) //当前元素小于基准
		{
			y = L->data[i];
			for (j = i - 1; j >= 0; j--) //移动
				L->data[j + 1] = L->data[j];
			L->data[0] = y;
		}
}

//顺序表的合并（不在实验一要求中）

void merge(SeqList *A, SeqList *B, SeqList *C)
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while (i <= A->last && j <= B->last) //将A和B的当前元素较小者复制到表C
		if (A->data[i] < B->data[j])
			C->data[k++] = A->data[i++];
		else
			C->data[k++] = B->data[j++];
	while (i <= A->last) //将A中剩余元素复制到表C
		C->data[k++] = A->data[i++];
	while (j <= B->last) //将B中剩余元素复制到表C
		C->data[k++] = B->data[j++];
	C->last = k - 1;
}

//顺序表的比较
int compare(int A[], int B[], int m, int n)
{
	int i = 0, ms = 0, ns = 0; //ms、ns为A’、B’的长度
	while (i < m && i < n && A[i] == B[i])
		i++;	//找最大共同前缀
	ms = m - i; //求A’的长度ms
	ns = n - i; //求B’的长度ns
	if (ms == ns && ms == 0)
		return 0;
	else if (ms == 0 && ns > 0 || ms > 0 && ns > 0 && A[i] < B[i])
		return -1;
	else
		return 1;
}
