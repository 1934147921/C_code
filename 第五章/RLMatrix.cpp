#include<stdio.h>
#include<stdlib.h>
#include "RLSMatrix.h"
//void CreateSMatrix(RLSMatrix &M);
//Status DestroySMatrix(RLSMatrix &M);
//Status CopySMatrix(RLSMatrix M, RLSMatrix &T);
//Status TransposeSMatrix(RLSMatrix M, RLSMatrix &T);
//Status PrintSMatrix(RLSMatrix M);
void CreateSMatrix(RLSMatrix &M)
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
	//init rpot集合
	initrpot(M);
	return;
}
Status initrpot(RLSMatrix &M)
{
	int num[MAXSIZE + 1];
	M.rpot[1] = 1;
	for (int i = 1; i <= M.mu; i++)
		num[i] = 0;
	for (int i = 1; i <= M.mu; i++)
		num[M.data[i].i]++;
	for (int i = 1; i <= M.mu; i++)
		M.rpot[i] = M.rpot[i - 1] + num[i - 1];
}
Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q)
{
	if (M.nu != N.mu) return ERROR;
	int ctemp[MAXSIZE + 1];
	Q.mu = M.mu;
	Q.nu = N.nu;
	Q.tu = 0;
	if (Q.mu*Q.nu!=0)
	{
		//接下来就是处理M的每一行
		for (int arow = 1; arow <= M.mu; arow++)
		{
			//初始化计数器ctemp
			for (int i = 1; i <= N.nu; i++)
				ctemp[i] = 0;
			//给Q.rpot进行初始化
			Q.rpot[arow] = Q.tu + 1;
			//下面处理的是N的每一列
			//t是列的上界
			int t;
			//Q的列号
			int ccol;
			//处理Q的每一行 M每一行的元素，要对N没一列的元素进行多次向乘
			for (int p = M.rpot[arow]; p < M.rpot[arow + 1]; p++)
			{
				int brow = M.data[p].j;
				if (brow < N.nu)  t= N.rpot[brow + 1];
				else t = N.tu + 1;
				for (int q = N.rpot[brow]; q < t; q++)
				{
					ccol = N.data[q].j;
					ctemp[ccol] += M.data[p].e.tp + N.data[p].e.tp;
				}//for q
			}//for p
			for (ccol = 1; ccol < N.nu; ccol++)
			{
				if (ctemp[ccol])
				{
					++Q.tu;
					if (Q.tu > MAXSIZE) return ERROR;
					Q.data[Q.tu].i = arow;
					Q.data[Q.tu].j = ccol;
					Q.data[Q.tu].e.tp = ctemp[ccol];
				}//if (ctemp[ccol])
			}//for ccol
		}//for
	}//if
	return;
}