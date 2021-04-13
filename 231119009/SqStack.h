#pragma once
#include"global.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ElemType char

typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;//��ǰ�Ѿ�����Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

//������ջ
Status InitStack(SqStack &S) {
	//������ջ
	S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ELemType));
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//����ջ��Ԫ��
Status GetTop(SqStack S) {
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR 
	if (S.top == S.base) return ERROR;
	return *(S.top - 1);
}
//��ջ
Status Push(SqStack &S, ElemType e) {
	if (S.top - S.base >= S.stacksize) {
		//ջ���ˡ�׷�Ӵ洢
		S.base = (ElemType*)realloc(S.base,
			(S.stacksize + STACKINCREMENT) * sizeof(ELemType));
		if (!S.base)exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}
//��ջ
Status Pop(SqStack &S, ElemType &e) {
	if (S.top == S.base) return ERROR;
	e = * --S.top;
	return OK;
}
//����ջ
/*
Status visit(SqStack S) {
	ElemType* i;
	for (i = S.top - 1; i >= S.base; i--) {
		cout << *i << ",";
	}
	cout << endl;
	return OK;
}*/
//ɾ��ջ
Status deleteStack(SqStack &S) {
	S.top = S.base;
	S.top = NULL;
	S.base = NULL;
	S.stacksize = 0;
	return OK;
}

//�ж�S�Ƿ�Ϊ��
Status isEmpty(SqStack &S) {
	if (S.top == S.base) return true;
	else return false;
}


//����ת��
/*
void conversion() {
	//�������������һ���Ǹ�ʮ������������ӡ�������ֵ��ȵİ˽�����
	SqStack S;
	int num, hex, e;
	InitStack(S);
	cout << "������Ҫת�������֣�ʮ���ƣ���";
	cin >> num;
	cout << "������Ҫת��Ŀ����ƣ�";
	cin >> hex;
	while (num) {
		Push(S,num % hex);
		num = num / hex;
	}
	while (!isEmpty(S)) {
		Pop(S, e);
		cout << e;
	}
	cout << endl;
}
*/
//����ƥ��

bool matching(char exp[]) {
	SqStack S;
	InitStack(S);
	int state = 1;
	ElemType e;
	int i = 0;
	while (exp[i] != '\0')
	{
		switch (exp[i]) {
		case '[': {
			Push(S, exp[i]);
			break;
		}
		case '(': {
			Push(S, exp[i]);
			break;
		}
		case ')': {
			if (!isEmpty(S) && GetTop(S) == '(') Pop(S, exp[i]);
			else state = 0;
			break;
		}
		case ']': {
			if (!isEmpty(S) && GetTop(S) == '[') Pop(S, exp[i]);
			else state = 0;
			break;
		}
		}
		i++;
	}
	if (state && isEmpty(S)) return true;
	else return false;
}