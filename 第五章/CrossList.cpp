#include<stdio.h>
#include<stdlib.h>
#include "CrossList.h"

//Status CreateSMatrix(CrossList &M);
//Status AddCrossList(CrossList &M, CrossList N);

Status CreateSMatrix(CrossList &M)
{
	
	int m = 3, n = 4, t = 4;
	OLNode data;
	data.down = NULL;
	data.right = NULL;

	printf("请输出行数、列数和非零值个数:");
	//scanf("%d%d%d", &m, &n, &t);
	M.mu = m; M.nu = n; M.tu = t;
	
	//给列表头链表开辟空间
	M.chead = (pOLNde)malloc(sizeof(OLNode)*(m + 1));
	if (!M.rhead) exit(0);
	
	//给行表头链表开辟空间
	M.rhead = (pOLNde)malloc(sizeof(OLNode)*(m + 1));
	if (!M.rhead) exit(0);
	
	//给行表头结点制NULL
	for (int i = 0; i <= m; i++)
	{
		pOLNde h = (pOLNde)malloc(sizeof(OLNode));
		h->i = i;
		h->j = 0;
		h->right = NULL;
		h->down = NULL;
		M.rhead[i].right = h;
	}
	
	
	//给列表头链表制NULL
	for (int i = 0; i <= n; i++)
	{
		pOLNde h = (pOLNde)malloc(sizeof(OLNode));
		h->i = 0;
		h->j = i;
		h->right = NULL;
		h->down = NULL;
		M.chead[i].down = h;
	}
	
	pOLNde Mh = (pOLNde)malloc(sizeof(OLNode));
	Mh->down = NULL;
	pOLNde fh = Mh;
	for (int i = 0; i <= n; i++)
	{
		pOLNde Nh = M.rhead[i].right;
		Mh->down = Nh;
		if (i == n)
			Mh->down = NULL;
		else
			Mh = Nh;
	}
	M.chead[0].down = fh->down;
	printf("请输出行号、列号和值:");
	scanf("%d%d%d", &data.i, &data.j, &data.e.tp);

	for (int c = 1; c <= t; c++)
	{
		pOLNde p;
		p = (pOLNde)malloc(sizeof(OLNode));
		if (!p) exit(0);
		p->i = data.i; p->j = data.j; p->e = data.e;
		p->down = NULL;
		p->right = NULL;
		pOLNde Nh = M.rhead[data.i].right;
		if (Nh->right == NULL)
			Nh->right = p;
		else
		{
			pOLNde q;
			q = M.rhead[data.i].right;
			for (; q->right && q->right->j < data.j; q = q->right);
			p->right = q->right;
			q->right = p;
		}//完成行插入

		//链接列的结点
		Mh = M.chead[data.j].down;
		if (Mh->down == NULL)
			Mh->down = p;
		else
		{
			pOLNde q;
			q = M.chead[data.j].down;
			for (; q->down && q->down->i < data.i; q = q->down);
			p->down = q->down;
			q->down = p->down;
		}//完成列插入
		printf("请输出行号、列号和值:");
		scanf("%d%d%d", &data.i, &data.j, &data.e.tp);
	}
	return OK;
}
Status PrintCrossList(CrossList &M)
{
	ElemType *data=nullptr;
	for (int col = 0; col < M.nu; col++)
		data[col].tp = 0;
	data = (ElemType *)malloc(sizeof(ElemType)*(M.nu));
	for (int i = 1; i <= M.mu; i++)
	{
		pOLNde pre = M.rhead[i].right->right;
		while (pre)
		{
			data[pre->j] = pre->e;
			pre = pre->right;
		}
		for (int j = 1; j <= M.nu; j++)
		{
			printf("%d\t", data[j].tp);
			if (!data[j].tp) data[j].tp = 0;
		}
		printf("\n");
	}
	return OK;
}