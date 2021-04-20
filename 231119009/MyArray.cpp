#include"MyArray.h"

int main() {

	TSMatrix a, b;
	int i;
	CreateSMatrix(a);
	cout << "原矩阵是：" << endl;
	PrintMatrix(a);
	TransposeSMatrix(a, b);
	cout << "矩阵a经过普通转置后得到矩阵b：" << endl;
	PrintMatrix(b);
	FastTransposeSMatrix(b, a);
	cout << "矩阵b经过快速转置后得到矩阵a：" << endl;
	PrintMatrix(a);

	return 0;
}