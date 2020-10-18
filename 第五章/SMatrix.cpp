#include<stdio.h>
#include<stdlib.h>
#include "SMatrix.h"
void CreateSMatrix(TSMatrix &M)
{
	printf("行数:");
	scanf("%d", &M.mu);
	printf("列数:");
	scanf("%d", &M.nu);
	printf("非零元个数:");
	scanf("%d", &M.tu);
	printf("按 元素行数、列数、元素值进行输入！\n");
	for (int i = 1; i <= M.tu; i++)
	{
		scanf("%d%d%d", M.data[i].i, M.data[i].j, M.data[i].e.tp);
	}
	return;
}

Status DestroySMatrix(TSMatrix &M)
{
	M.mu = 0;
	M.nu = 0;
	for (int i = 1; i <= M.tu; i++)
	{
		M.data[i].i = 0;
		M.data[i].j = 0;
		M.data[i].e.tp = 0;
	}
	M.tu = 0;
	return OK;
}
Status CopySMatrix(TSMatrix M, TSMatrix &T)
{
	T.mu = M.mu;
	T.nu = M.nu;
	T.tu = M.tu;
	for (int i = 1; i <= M.tu; i++)
	{
		T.data[i] = M.data[i];
	}
	return OK;
}
Status PrintSMatrix(TSMatrix M)
{
	for (int i = 1; i <= M.mu; i++)
	{
		for (int j = 1; j <= M.nu; j++)
		{
			if (i == M.data[i].i&&j == M.data[i].j)
				printf("%d\t", M.data[i].e.tp);
			else
				printf("0\t");
		}
		printf("\n");
	}
	return OK;
}
Status TransposeSMatrix(TSMatrix M, TSMatrix &T)
{
	int num[100];
	int cpot[100];
	cpot[1] = 1;
	T.mu = M.nu;
	T.nu = T.mu;
	T.tu = M.tu;
	if (M.tu)
	{
		//初始化num集合
		for (int i = 1; i <= M.nu; i++)
			num[i] = 0;
		//给把没一行的元素个数给num集合中
		for (int i = 1; i <= M.nu; i++)
			num[M.data[i].j]++;
		
		//给copt集合装数字
		for (int i = 2; i <= M.nu; i++)
			cpot[i] = cpot[i - 1] + num[i - 1];

		//准备工作都完成后进行转置
		for (int i = 1; i <=M.nu; i++)
		{
			T.data[cpot[i]].i = M.data[i].j;
			T.data[cpot[i]].j = M.data[i].i;
			T.data[cpot[i]].e = M.data[i].e;
			++cpot[i];
		}
	}
	return OK;
}