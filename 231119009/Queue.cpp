#include"SqQueue.h"
/*
void main() {
	SqQueue queue1, queue2;
	int n , len , num;
	QElemType Del1, Del2 , ret;
	InitQueue(queue1);
	InitQueue(queue2);

	cout << "���������������������";
	cin >> n;

	EnQueue(queue1 , 0); //�Զ���1��ʼ��
	EnQueue(queue1 , 1);
	EnQueue(queue1 , 0);
	cout << "����������£�" << endl;
	cout << "1" << endl;

	for (int i = 0; i < n - 1; i++)
	{
		EnQueue(queue2 , 0);
		len = QueueLength(queue1);
		for (int j = 0; (len != 1); j++)  //����1�ƶ�������2��ֱ������1ֻʣ���һ��Ԫ��0
		{
			DeQueue(queue1 ,Del1);
			Del2 = GetFront(queue1);
			num = Del1 + Del2;
			EnQueue(queue2 , num);
			len--;
		}
		ClearQueue(&queue1); //��ն���1
		EnQueue(queue2, 0);
		len = QueueLength(queue2);
		for (int j = 0; j < len; j++)
		{
			DeQueue(queue2 , ret);
			if (ret != 0)
			{
				cout << ret << " ";
			}
			EnQueue(queue1 , ret);
		}
		cout << endl;
	}
	cout << endl << "231119009 ������" << endl;
}*/