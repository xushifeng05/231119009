#include"MyArray.h"

int main() {

	TSMatrix a, b;
	int i;
	CreateSMatrix(a);
	cout << "ԭ�����ǣ�" << endl;
	PrintMatrix(a);
	TransposeSMatrix(a, b);
	cout << "����a������ͨת�ú�õ�����b��" << endl;
	PrintMatrix(b);
	FastTransposeSMatrix(b, a);
	cout << "����b��������ת�ú�õ�����a��" << endl;
	PrintMatrix(a);

	return 0;
}