#pragma once
#include "Tree.h"

typedef struct {
	unsigned int weight;  //权重非负
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

typedef char** Huffmancode;

void Select(HuffmanTree &HT, int n, int &s1, int &s2) {
	//在HT[]中选择parent为0且weight最小的两个结点
	//其序号分别为s1和s2
	int i;
	s1 = -1; s2 = -1;
	for ( i = 1; i < n; i++)
	{
		if (s1 == -1)
			s1 = i;
		else if (HT[i].weight < HT[s1].weight)
		{
			s2 = s1;
			s1 = i;
		}
		else if (s2 == -1 || HT[i].weight < HT[s2].weight)
			s2 = i;
	}
}

void HuffmanCoding(HuffmanTree &HT, Huffmancode &HC, int *w, int n)
{
	//求出n个字符的哈夫曼编码HC，w数组存储权值
	int i, m, s1, s2, start;
	char* cd;
	unsigned int c, f;
	if (n <= 1)return;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	for ( i = 1; i <= n; i++)
	{
		HT[i].weight = w[i - 1];
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (i = n + 1; i <= m; i++)
	{
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
}