#include "Graph.h"

void main() {
	int choice = 0;
	Graph G;
	InitGraph(G);
	while (1)
	{
		menu();
		cout << "请输入要执行的操作序号：";
		cin >> choice;
		if (4 == choice) break;
		switch (choice)
		{
		case 1:CreateGraph(G); break;
		case 2:BFSTraverse(G); break;
		case 3:DFSTraverse(G); break;
		case 4: break;
		}
	}
	cout << "231119009许世烽";
}