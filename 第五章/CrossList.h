#pragma once
#define MAXSIZE 12500
#define OK 1;
#define ERROR 0;
typedef int Status;

typedef struct {
	int tp;
}ElemType;

typedef struct OLNode {
	//�к�
	int i;
	//�к�
	int j;
	//����ֵ
	ElemType e;
	//��ָ����
	struct OLNode *right;
	//��ָ����
	struct OLNode *down;
}OLNode, *pOLNde;

typedef struct {
	//�б�ͷָ����
	pOLNde rhead;
	//�б�ͷָ����
	pOLNde chead;
	//����
	int mu;
	//����
	int nu;
	//����Ԫ�ظ���
	int tu;
}CrossList, *pCrossList;

Status CreateSMatrix(pCrossList &M);
Status AddCrossList(CrossList &M, CrossList N);