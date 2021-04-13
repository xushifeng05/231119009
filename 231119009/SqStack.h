#pragma once
#include"global.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ElemType char

typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;//当前已经分配的存储空间，以元素为单位
}SqStack;

//构建空栈
Status InitStack(SqStack &S) {
	//构建空栈
	S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ELemType));
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//查找栈顶元素
Status GetTop(SqStack S) {
	//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR 
	if (S.top == S.base) return ERROR;
	return *(S.top - 1);
}
//入栈
Status Push(SqStack &S, ElemType e) {
	if (S.top - S.base >= S.stacksize) {
		//栈满了。追加存储
		S.base = (ElemType*)realloc(S.base,
			(S.stacksize + STACKINCREMENT) * sizeof(ELemType));
		if (!S.base)exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}
//出栈
Status Pop(SqStack &S, ElemType &e) {
	if (S.top == S.base) return ERROR;
	e = * --S.top;
	return OK;
}
//遍历栈
/*
Status visit(SqStack S) {
	ElemType* i;
	for (i = S.top - 1; i >= S.base; i--) {
		cout << *i << ",";
	}
	cout << endl;
	return OK;
}*/
//删除栈
Status deleteStack(SqStack &S) {
	S.top = S.base;
	S.top = NULL;
	S.base = NULL;
	S.stacksize = 0;
	return OK;
}

//判断S是否为空
Status isEmpty(SqStack &S) {
	if (S.top == S.base) return true;
	else return false;
}


//进制转换
/*
void conversion() {
	//对于输入的任意一个非负十进制整数，打印输出与其值相等的八进制数
	SqStack S;
	int num, hex, e;
	InitStack(S);
	cout << "请输入要转换的数字（十进制）：";
	cin >> num;
	cout << "请输入要转换目标进制：";
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
//括号匹配

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