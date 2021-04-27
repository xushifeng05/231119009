#pragma once

#include"global.h"
#include<string.h>

//树节点结构体
typedef struct BiNode {
	char data;
	struct BiNode* lchild, * rchild;
}BiTNode, *BiTree;

void InitBiTree(BiTree T) {
	T = NULL;
}

//创建树
void Create(BiTree& T) {
	char ch;
	cin >> ch;
	if (ch == '*')
	{
		T = NULL;
	}
	else
	{
		T = (BiNode *)malloc(sizeof(BiNode));
		T->data = ch;
		Create(T->lchild);
		Create(T->rchild);
	}
}

//访问节点
void visit(char c) {
	cout << c << "->";
}

//先序遍历
void PreOrderTraverse(BiTree T) {
	if (T)
	{
		visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

//中序遍历
void InOrderTraverse(BiTree T) {
	if (T)
	{
		InOrderTraverse(T->lchild);
		visit(T->data);
		InOrderTraverse(T->rchild);
	}
}

//后序遍历
void PostOrderTraverse(BiTree T) {
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		visit(T->data);
	}
}

//计算树的深度
int depth(BiTree T) {
	int ldeep, rdeep;
	if (!T)return 0;
	else
	{
		ldeep = depth(T->lchild);
		rdeep = depth(T->rchild);
		return ldeep > rdeep ? ldeep + 1 : rdeep + 1;
	}
}

//231119009许世烽