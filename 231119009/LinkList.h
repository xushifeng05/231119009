#pragma once
#include "global.h"

#define ElemType int

//��������ṹ
typedef struct LNode {
	ElemType data;
	struct  LNode* next;
}LNode,*LinkList;

//�����µ�������
void CreateList_L(LinkList &L) {
	LinkList p; int n;
	cout << "������Ԫ�صĸ�����";
	cin >> n;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i > 0 ; i--)
	{
		p = (LinkList)malloc(sizeof(LNode));
		cout << "�������"<< i <<"��Ԫ�أ�";
		cin >> p->data;
		p->next = L->next; L->next = p;
	}
}

//����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
Status GetElem_L(LinkList L , int i , ElemType &e) {
	LinkList p;
	int j = 1;
	p = L->next; //��ʼ��pָ���һ����㣬jΪ������
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}

//����Ԫ��
Status ListInsert_L(LinkList &L , int i , ElemType e) {
	LinkList p = L ,s;
	int j = 0;
	while (p && j < i-1)
	{
		p = p->next; ++j;
	}
	if (!p || j > i - 1) return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//ɾ��
Status ListDelete_L(LinkList &L , int i , ElemType &e) {
	LinkList p , q;
	int j;
	p = L;
	j = 0;
	while (p->next && j < i-1)
	{
		p = p->next; ++j;
	}
	if (!(p->next) || j > i-1) return ERROR;
	q = p->next; p->next = q->next;
	e = q->data; free(q);
	return OK;
}

//�ϲ�
void MergeList_L(LinkList &La , LinkList &Lb , LinkList &Lc) {
	LinkList pa = La->next , pb = Lb->next;
	LinkList pc = La; Lc = La;
	while (pa && pb) {
		if (pa->data <= pb->data)
		{
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else {
			pc->next = pb; pc = pb; pb = pb->next;
		}
		pc->next = pa ? pa : pb;
	}
}

//�������
void Print(LinkList L) {
	cout << "�����˴β����󣬵�����Ϊ��";
	LinkList p = L->next;
	while (p) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}