//带表头结点的单链表的运算
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct Node
{
	int data;
	struct Node* next;
}LNode, * LinkList;           //Node表结点的结构类型， LinkList指向Node结点的指针类型；

//建立带头结点的单链表
LinkList createLinkList(int n)
{
	LNode* head, * p, * q;
	int i, info;

	head = (LNode*)malloc(sizeof(LNode));
	if (!head) return NULL;

	head->next = NULL;
	q = head;

	printf("\n Please input %d  elements' data by ascending: ", n);
	for (i = 1; i <= n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));
		if (!p) return NULL;

		printf("\n Input the %dth element data: ", i);
		scanf("%d", &info);
		p->data = info;
		q->next = p; p->next = NULL;  //p指向的结点插入单链表的表尾
		q = p;                       //q总是指向当前单链表的最后一个结点（表尾）
	}
	return head;
}
//输出单链表中的结点信息
void displayLinkList(LinkList head)
{
	LNode* p;

	int i = 0;
	p = head->next;
	while (p)
	{
		printf("\n Output the %dth element's data  %d:  ", ++i, p->data);
		p = p->next;

	}

}
//????????????С
int compare(int a, int b)
{
	if (a < b)
		return -1;
	else
		if (a == b)
			return 0;
		else
			return -2;
}
//求两个带头结点单链表的交集，每个单链表中的元素递增有序
LinkList intersectionDList(LinkList La, LinkList Lb)
{
	LinkList Lc;
	LNode* pa, * pb, * pc, * pt;        //pt指向新申请的结点，pa,pb,pc指向三个单链表的当前结点
	int tmp;
	pa = La->next; pb = Lb->next;
	pc = (LNode*)malloc(sizeof(LNode));
	if (!pc) return NULL;
	Lc = pc;

	while (pa && pb)
	{
		tmp = compare(pa->data, pb->data);
		switch (tmp)
		{
		case -1:
		{
			pa = pa->next;
			break;
		}
		case 0:
		{
			pt = (LNode*)malloc(sizeof(LNode));   //pt????????????
			pt->data = pa->data;
			pc->next = pt;                        //??????Lc??????β
			pt->next = NULL;
			pa = pa->next; pb = pb->next; pc = pc->next;  //???????????????????
			break;
		}
		case -2:
		{
			pb = pb->next;
			break;
		}
		}

	}//end of while

	return Lc;

}

//???????????????????????????
//La,Lb?е???????????????
//?鲢La??Lb??????????????Lc???????????
LinkList mergeDList(LinkList La, LinkList Lb)
{
	LinkList Lc;
	LNode* pa, * pb, * pc, * pt;
	int tmp;
	pa = La->next;
	pb = Lb->next;

	pc = (LNode*)malloc(sizeof(LNode));
	if (!pc) return NULL;
	Lc = pc;
	while (pa && pb)
	{
		tmp = compare(pa->data, pb->data);
		switch (tmp)
		{
		case -1:
		{
			pt = (LNode*)malloc(sizeof(LNode));
			pt->data = pa->data;
			pc->next = pt;   pt->next = NULL;
			pa = pa->next; pc = pc->next;
			break;
		}
		case 0:
		{
			pt = (LNode*)malloc(sizeof(LNode));
			pt->data = pa->data;
			pc->next = pt;   pt->next = NULL;

			pa = pa->next; pb = pb->next; pc = pc->next;
			break;
		}
		case -2:
		{
			pt = (LNode*)malloc(sizeof(LNode));
			pt->data = pb->data;
			pc->next = pt;   pt->next = NULL;

			pb = pb->next; pc = pc->next;
			break;
		}
		}

	}//end of while
	pa = pa ? pa : pb;                 //???????????????????????Lc???β
	while (pa)
	{
		pt = (LNode*)malloc(sizeof(LNode));
		pt->data = pa->data;
		pc->next = pt;   pt->next = NULL;

		pa = pa->next; pc = pc->next;

	}
	return Lc;

}
main()
{
	int n, m;
	LinkList La, Lb, Lc;

	printf("\n the number of n(0<n<100):");
	scanf("%d", &n);
	La = createLinkList(n);             //????????n?????????????????La
	printf("\n Output La list-------");
	displayLinkList(La);              //???La?е????

	printf("\n the number of m(0<m<100):");
	scanf("%d", &m);
	Lb = createLinkList(m);
	printf("\n Output Lb list-------");
	displayLinkList(Lb);

	Lc = intersectionDList(La, Lb);
	printf("\n Output Lc=La??Lb -------");
	displayLinkList(Lc);

	Lc = mergeDList(La, Lb);
	printf("\n Output Lc=La??Lb -------");
	displayLinkList(Lc);

	_getch();


}
