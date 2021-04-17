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

	cout << "拼接两个字符串后,";
	Concat(T, S, P);
	StrOutPut(T);

	cout << "串的长度:" << GetStrLength(T) <<endl;

	SubString(Sub,T,2,4);
	cout << "2到4返回需要的字符子串:";
	StrOutPut(Sub);
	cout << endl;

	cout << "向T中插入Sub串的插入：";
	StrInsert(T , 1 , Sub);
	StrOutPut(T);
	cout << endl;
    
	StrIndex(T,S,pos);
	cout << "BF算法查询abacacadf字串的位置:" << pos <<endl;
	

	cout << "231119009 许世烽" << endl;
	return 0;
}