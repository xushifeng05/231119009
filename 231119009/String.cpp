#include"MyString.h"

int main() {
	char s[] = "abacacadfajdhfaljd";
	char p[] = "adfajehfaejh";

	SString S, P;
	SString T;

	StrAssign(S,s);
	StrAssign(P, p);

	cout << "ƴ�������ַ�����,";
	Concat(T, S, P);
	StrOutPut(T);

	cout << "231119009 ������" << endl;
	return 0;
}