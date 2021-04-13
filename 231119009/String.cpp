#include"MyString.h"

int main() {
	char s[] = "abacacadfajdhfaljd";
	char p[] = "adfajehfaejh";

	SString S, P;
	SString T;

	StrAssign(S,s);
	StrAssign(P, p);

	cout << "拼接两个字符串后,";
	Concat(T, S, P);
	StrOutPut(T);

	cout << "231119009 许世烽" << endl;
	return 0;
}