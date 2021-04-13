#pragma once
#include "global.h"

#define ElemType int

//单向链表结构
typedef struct LNode {
	ElemType data;
	struct  LNode* next;
}LNode,*LinkList;

//创建新单向链表
void CreateList_L(LinkList &L) {
	LinkList p; int n;
	cout << "请输入元素的个数：";
	cin >> n;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i > 0 ; i--)
	{
		p = (LinkList)malloc(sizeof(LNode));
		cout << "请输入第"<< i <<"个元素：";
		cin >> p->data;
		p->next = L->next; L->next = p;
	}
}

//当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
Status GetElem_L(LinkList L , int i , ElemType &e) {
	LinkList p;
	int j = 1;
	p = L->next; //初始化p指向第一个结点，j为计数器
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}

//插入元素
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

//删除
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

//合并
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

//输出链表
void Print(LinkList L) {
	cout << "经过此次操作后，单链表为：";
	LinkList p = L->next;
	while (p) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}