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
	//��i ��  ��j��
	int i, j;
}Triple;

typedef union {
	Triple data[MAXSIZE + 1];	//����Ԫ��Ԫ���data[0],����
	int mu;						//����
	int nu;						//����
	int tu;						//����Ԫ����
}TSMatrix;

void CreateSMatrix(TSMatrix &M);
Status DestroySMatrix(TSMatrix &M);
Status CopySMatrix(TSMatrix M, TSMatrix &T);
Status TransposeSMatrix(TSMatrix M, TSMatrix &T);
Status PrintSMatrix(TSMatrix M);

//