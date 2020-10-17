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
	int rpot[MAXSIZE + 1];		//���е�һ������Ԫ��λ�ñ�
	int mu;						//����
	int nu;						//����
	int tu;						//����Ԫ����
}RLSMatrix;

void CreateSMatrix(RLSMatrix &M);
Status initrpot(RLSMatrix &M);
Status DestroySMatrix(RLSMatrix &M);
Status CopySMatrix(RLSMatrix M, RLSMatrix &T);
Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q);
Status PrintSMatrix(RLSMatrix M);
