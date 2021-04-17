#include "global.h"
#include<string>

#define MAXSTRLEN 80

//����˳�����
typedef struct {
	unsigned char data[MAXSTRLEN + 1];
	int length;
}SString;

//�ѷ���
typedef struct {
	char* ch;
	int length;
}HString;

//���Ŀ����洢
typedef struct Chunk {
	char ch[MAXSTRLEN];
	struct Chunk* next;
};

typedef struct {
	Chunk* head, * tail;
	int curlen;
}LSting;

//ͨ��һ���ַ�����cstr������һ��SString
Status StrAssign(SString &s,char cstr[]) {
	int i;
	for ( i = 1; cstr[i - 1] != '\0' ; i++)
	{
		if (i > MAXSTRLEN) return ERROR;
		s.data[i] = cstr[i - 1];
	}
	s.length = i - 1;
	cout << "�ַ�����Ϊ��" << s.length << endl;
	return OK;
}

//�ַ��������
Status StrOutPut(SString s) {
	int i;
	cout << "����Ԫ��Ϊ��";
		for ( i = 1; i <= s.length; i++)
		{
			cout << s.data[i] << ",";
		}
	cout << endl;
	return OK;
}

//�ַ�����ƴ��
Status Concat(SString &T , SString S1 , SString S2) {
	int i;
	bool uncut;
	if (S1.length + S2.length <= MAXSTRLEN)
	{
		for ( i = 1; i <= S1.length; i++)
		{
			T.data[i] = S1.data[i];
		}
		for (i = S1.length + 1; i <= S1.length + S2.length; i++)
			T.data[i] = S2.data[i - S1.length];
		T.length = S1.length + S2.length;
		uncut = TRUE;
	}else if (S1.length < MAXSTRLEN)
	{
		for (i = 1; i <= S1.length; i++)
		{
			T.data[i] = S1.data[i];
		}
		for (i = S1.length + 1; i <= MAXSTRLEN; i++)
			T.data[i] = S2.data[i - S1.length];
		T.length =MAXSTRLEN;
		uncut = FALSE;
	}
	else {
		for (i = 0; i < MAXSTRLEN; i++)
			T.data[i] = S1.data[i];
		uncut = FALSE;
	}
	return OK;
}

//������Ҫ�����ַ���
Status SubString(SString &Sub , SString S, int pos , int len) {
	int i;
	if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
		return ERROR;
	for (i = 1; i <= len; i++)
		Sub.data[i] = S.data[pos + i - 1];
	Sub.length = len;
	return OK;
}

//���ĳ���
Status GetStrLength(SString S) {
	return S.length;
}

//�����
Status ClearStr(SString &S) {
	int i;
	for ( i = 1; i < S.length; i++)
	{
		S.data[i] = '\0';
		S.length = 0;
		return OK;
	}
}

//�жϴ��Ƿ�Ϊ��
Status StrIsEmpty(SString S) {
	if (S.length == 0)
		return OK;
	else
		return ERROR;
}

//����S���Ƹ�T
Status StrCopy(SString &T,SString S) {
	int i;
	for ( i = 0; i < S.length; i++)
	{
		T.data[i] = S.data[i];
	}
	return OK;
}

//��ѯ�Ӵ���BF�㷨
Status StrIndex(SString S , SString T , int pos ) {
	int i = pos + 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.data[i] == T.data[i])
		{
			++i; ++j;
		}
		else {
			i = i - j + 2; j = 1;
		}
	}
	if (j > T.length) return i - T.length;
	else return FALSE;
}

//�жϴ��Ƿ����
bool StrCompare(SString S,SString T) {
	if (T.length != S.length)
		return FALSE;
	else
	{
		int i;
		for ( i = 1; i < T.length; i++)
		{
			if (T.data[i] != S.data[i])
				return FALSE;
		}
	}
	return TRUE;
}

//���Ĳ���
Status StrInsert(SString& S, int pos, SString T) {
	int i;
	if (S.length + T.length > MAXSTRLEN || pos <= 0 || pos > S.length)
		return ERROR;
	for (i = T.length + S.length; i >= S.length; i--)
		S.data[i] = S.data[i - T.length];
	for (i = 1; i <= T.length; i++)
		S.data[pos + i - 1] = T.data[i];
	S.length += T.length;
	return OK;
}

//���ٴ�
Status DestroyStr(SString &S) {
	int i;
	for (i = MAXSTRLEN; i >= 0; i--)
		free(S.data + i);
	return OK;
}

//kmp��next����
void get_next(SString S, int* next) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < S.length)
	{
		if (j == 0 || S.data[i] == S.data[j])
		{
			++i; ++j; next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
	cout << "ģʽ����next����Ϊ��";
	for ( i = 0; i < j; i++)
	{
		cout << next[i] << ",";
	}
}

//kmp�㷨
int KMP(SString S, SString T) {
	int i = 1;
	int j = 1;
	int next[MAXSTRLEN];
	get_next(T , next);
	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.data[i] == T.data[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}