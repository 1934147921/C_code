#pragma once
#define MAXSIZE 12500
#define OK 1;
#define ERROR 0;
typedef int Status;

typedef struct {
	int tp;
}ElemType;

typedef struct OLNode {
	//行号
	int i;
	//列号
	int j;
	//数据值
	ElemType e;
	//右指针域
	struct OLNode *right;
	//下指针域
	struct OLNode *down;
}OLNode, *pOLNde;

typedef struct {
	//行表头指针域
	pOLNde rhead;
	//列表头指针域
	pOLNde chead;
	//行数
	int mu;
	//列数
	int nu;
	//非零元素个数
	int tu;
}CrossList, *pCrossList;

Status CreateSMatrix(pCrossList &M);
Status AddCrossList(CrossList &M, CrossList N);