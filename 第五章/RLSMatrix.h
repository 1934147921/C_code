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
	int rpot[MAXSIZE + 1];		//各行第一个非零元的位置表
	int mu;						//行数
	int nu;						//列数
	int tu;						//非零元个数
}RLSMatrix;

void CreateSMatrix(RLSMatrix &M);
Status initrpot(RLSMatrix &M);
Status DestroySMatrix(RLSMatrix &M);
Status CopySMatrix(RLSMatrix M, RLSMatrix &T);
Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q);
Status PrintSMatrix(RLSMatrix M);
