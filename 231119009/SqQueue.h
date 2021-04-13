#pragma once
#include "global.h"

#define MAXQSIZE 100
#define QElemType int

typedef struct {
	QElemType* base;
	int front;  //��ͷָ��
	int rear;   //��βָ��
}SqQueue;

//����һ���ն���Q
Status InitQueue(SqQueue &Q) {
	Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

//���ضӳ�
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//����Ԫ��eΪQ���µĶ�βԪ��
Status EnQueue(SqQueue &Q , QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;//������
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1) % MAXQSIZE;
	return OK;
}

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK��
//���򷵻�ERROR
Status DeQueue(SqQueue &Q , QElemType &e) {
	if (Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

//ȡ��ͷԪ��
int GetFront(SqQueue q) {
	if (q.rear == q.front)
	{
		return ERROR;
	}
	return q.base[q.front];
}

//��ն���
int ClearQueue(SqQueue *q) {
	if (q == NULL)
	{
		return ERROR;
	}
	q->front = q->rear;
	return OK;
}

