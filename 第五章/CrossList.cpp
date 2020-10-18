#include<stdio.h>
#include<stdlib.h>
#include "CrossList.h"

//Status CreateSMatrix(CrossList &M);
//Status AddCrossList(CrossList &M, CrossList N);

Status CreateSMatrix(pCrossList &M)
{
	if (M) free(M);
	int m, n, t;
	OLNode data;
	data.down = NULL;
	data.right = NULL;

	printf("请输出行号、列号和值：\n:");
	scanf("%d%d%d", &m, &n, &t);
	M->mu = m; M->nu = n; M->tu = t;
	
	//给列表头链表初始化
	M->chead = (pOLNde)malloc(sizeof(OLNode)*(m + 1));
	if (!M->rhead) exit(0);
	
	//给行表头链表初始化
	M->rhead = (pOLNde)malloc(sizeof(OLNode)*(m + 1));
	if (!M->rhead) exit(0);
	
	//给行表头链表制NULL
	for (int i = 0; i <= n; i++)
	{
		pOLNde h = (pOLNde)malloc(sizeof(OLNode));
		h->right = NULL;
		h->down = NULL;
		M->rhead[i].right = h;
	}

	//给列表头链表制NULL
	for (int i = 0; i <=m; i++)
		M->chead[i].down = NULL;
	
	//pOLNde 

	printf("请输出行号、列号和值：\n:");
	scanf("%d%d%d", &data.i, &data.j, &data.e.tp);

	for (int c = 1; c <= t; c++)
	{
		pOLNde p;
		p = (pOLNde)malloc(sizeof(OLNode));
		if (!p) exit(0);
		p->i = data.i; p->j = data.j; p->e = data.e;
		p->down = NULL;
		p->right = NULL;
		if (M->rhead[data.i].right == NULL)
			M->rhead[data.i].right = p;
		else
		{
			pOLNde q;
			q = M->rhead[data.i].right;
			for (; q&&q->right->j < data.j; q = q->right);
			p->right = q->right;
			q->right = p;
		}//完成行插入

			
	}
}