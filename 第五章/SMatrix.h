#pragma once
#define MAXSIZE 12500
#define OK 1;
#define ERROR 0;

typedef int Status;
typedef struct {
	int tp;
}ElemType;

typedef struct {
	ElemType e;
	//第i 行  第j列
	int i, j;
}Triple;

typedef union {
	Triple data[MAXSIZE + 1];	//非零元三元组表，data[0],不用
	int mu;						//行数
	int nu;						//列数
	int tu;						//非零元个数
}TSMatrix;

void CreateSMatrix(TSMatrix &M);
Status DestroySMatrix(TSMatrix &M);
Status CopySMatrix(TSMatrix M, TSMatrix &T);
Status TransposeSMatrix(TSMatrix M, TSMatrix &T);
Status PrintSMatrix(TSMatrix M);

//