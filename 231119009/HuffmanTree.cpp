#pragma warning(disable:4996);
#include "HuffmanTree.h"

void main() {
	int i, n;
	int* w;
	TElemType* ch;
	HuffmanTree HT;
	Huffmancode HC;
	cout << "请输入编码字符的数量：";
	cin >> n;
	ch = (TElemType*)malloc(n * sizeof(TElemType));
	w = (int*)malloc(n * sizeof(int));
	cout << "请依次输入各结点字符值：";
	for ( i = 0; i < n; i++)
		cin >> ch[i];

	cout << "请依次输入各结点权值：";
	for (i = 0; i < n; i++)
		cin >> w[i];


	HC = (char**)malloc((n + 1) * sizeof(char*));
	HT = (HuffmanTree)malloc((2 * n + 1 + 1) * sizeof(HTNode));
	HuffmanCoding(HT, HC, w, n);
	for ( i = 1; i < n + 1; i++)
	{
		cout << "字符" << ch[i - 1] << "的哈夫曼编码为：";
		cout << HC[i] << endl;
		free(HC[i]);
	}
	free(HC);
	free(HT);

	cout <<endl << "231119009许世烽" << endl;
}