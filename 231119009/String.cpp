#include"MyString.h"

int main() {
	char s[] = "abacacadf";
	char p[] = "adfajehfaejh";

	int pos = 9;

	SString Sub;
	SString S, P;
	SString T;

	StrAssign(S,s);
	StrAssign(P, p);

	cout << "ƴ�������ַ�����,";
	Concat(T, S, P);
	StrOutPut(T);

	cout << "���ĳ���:" << GetStrLength(T) <<endl;

	SubString(Sub,T,2,4);
	cout << "2��4������Ҫ���ַ��Ӵ�:";
	StrOutPut(Sub);
	cout << endl;

	cout << "��T�в���Sub���Ĳ��룺";
	StrInsert(T , 1 , Sub);
	StrOutPut(T);
	cout << endl;
    
	StrIndex(T,S,pos);
	cout << "BF�㷨��ѯabacacadf�ִ���λ��:" << pos <<endl;
	

	cout << "231119009 ������" << endl;
	return 0;
}