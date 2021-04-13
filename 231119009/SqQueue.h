#pragma once
#include "global.h"

#define MAXQSIZE 100
#define QElemType int

typedef struct {
	QElemType* base;
	int front;  //队头指针
	int rear;   //队尾指针
}SqQueue;

//构造一个空队列Q
Status InitQueue(SqQueue &Q) {
	Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

//返回队长
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//插入元素e为Q的新的队尾元素
Status EnQueue(SqQueue &Q , QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;//队列满
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1) % MAXQSIZE;
	return OK;
}

//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；
//否则返回ERROR
Status DeQueue(SqQueue &Q , QElemType &e) {
	if (Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

//取队头元素
int GetFront(SqQueue q) {
	if (q.rear == q.front)
	{
		return ERROR;
	}
	return q.base[q.front];
}

//清空队列
int ClearQueue(SqQueue *q) {
	if (q == NULL)
	{
		return ERROR;
	}
	q->front = q->rear;
	return OK;
}

