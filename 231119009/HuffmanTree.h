#include "global.h"


typedef char TElemType;
typedef int Status;

typedef struct {
	unsigned int weight;  //Ȩ�طǸ�
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

typedef char** Huffmancode;

void Select(HuffmanTree &HT, int n, int &s1, int &s2) {
	//��HT[]��ѡ��parentΪ0��weight��С���������
	//����ŷֱ�Ϊs1��s2
	int i;
	s1 = -1; s2 = -1;
	for ( i = 1; i <= n; i++)
		if (HT[i].parent == 0)
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
	//���n���ַ��Ĺ���������HC��w����洢Ȩֵ
	int i, m, s1, s2, start;
	char* cd;
	unsigned int c, f;
	if (n <= 1)return;
	m = 2 * n - 1;            //Ҷ�ӽ������
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	for ( i = 1; i <= n; i++) //Ҷ�ӽ��ĳ�ʼ��
	{
		HT[i].weight = w[i - 1];
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (i = n + 1; i <= m; i++)  //��Ҷ�ӽ��ĳ�ʼ��
	{
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for ( i = n + 1; i <= m; i++) //������������
	{
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	//--- ��Ҷ�ӵ���������ÿһ���ַ��Ĺ��������� ----
	cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for ( i = 1; i <= n; ++i)
	{
		start = n - 1;        //�����������λ��
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
			if (HT[f].lchild == c) cd[--start] = '0';
			else cd[--start] = '1';
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
	//231119009������
}