#pragma warning(disable:4996);
#include "HuffmanTree.h"

void main() {
	int i, n;
	int* w;
	TElemType* ch;
	HuffmanTree HT;
	Huffmancode HC;
	cout << "����������ַ���������";
	cin >> n;
	ch = (TElemType*)malloc(n * sizeof(TElemType));
	w = (int*)malloc(n * sizeof(int));
	cout << "���������������ַ�ֵ��";
	for ( i = 0; i < n; i++)
		cin >> ch[i];

	cout << "��������������Ȩֵ��";
	for (i = 0; i < n; i++)
		cin >> w[i];


	HC = (char**)malloc((n + 1) * sizeof(char*));
	HT = (HuffmanTree)malloc((2 * n + 1 + 1) * sizeof(HTNode));
	HuffmanCoding(HT, HC, w, n);
	for ( i = 1; i < n + 1; i++)
	{
		cout << "�ַ�" << ch[i - 1] << "�Ĺ���������Ϊ��";
		cout << HC[i] << endl;
		free(HC[i]);
	}
	free(HC);
	free(HT);

	cout <<endl << "231119009������" << endl;
}