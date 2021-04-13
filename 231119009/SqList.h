#include "global.h"

#define ElemType int
#define LISTINCREMENT 10

typedef struct {
	ElemType* elem; //˳���Ļ���ַ
	int listsize; //˳���Ĵ洢����
	int length; //˳����Ԫ�ظ���
}SqList;


//��ʼ��
Status InitList_sq(SqList &L) {
	L.elem = (ElemType*)malloc(100*sizeof(int));//����洢�ռ�
	if (!L.elem) {
		exit(OVERFLOW);
	}
	L.listsize = 100;
	L.length = 0;
	return OK;
}


//��˳���β������Ԫ��
Status addElem_Sq(SqList &L, ElemType e) {
	L.elem[L.length] = e; //�����Ա�����һ��Ԫ�ظ�ֵΪe
	L.length++;
	return OK;
}

//��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
Status ListInsert_Sq(SqList &L , int i , ElemType e) {
	//i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)+1
	if (i<1 || i>L.length+1)
	{
		return ERROR;
	}
	if (L.length >= L.listsize) {//��ǰ�洢�ռ����������ӷ���
		ElemType* newbase;
		newbase = (ElemType*)realloc(L.elem,
			(L.listsize+LISTINCREMENT)*sizeof(int));
		if (!newbase) {
			exit(OVERFLOW);
		}
		L.elem = newbase;
		L.listsize++;
	}
	ElemType *q , *p;
	q = &(L.elem[i - 1]);//q�����λ��
	for (p = &(L.elem[L.length-1]); p >= q ; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	++L.length;
	return OK;
}

//��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
Status ListDelete_Sq(SqList &L , int i , ElemType &e) {
	//i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)
	if (i<1 || i>L.length)
	{
		return ERROR;
	}
	ElemType *p , *q;
	p = &(L.elem[i]);
	e = *p;
	q = L.elem + L.length - 1;
	for ( p ; p <= q ; ++p)
	{
		*(p - 1) = *p;
	}
	--L.length;
	return OK;
}

//��˳�����Ա�L�в��ҵ�һ��ֵ��e����EQ������Ԫ��λ��
ElemType LocateElem_Sq(SqList L , ElemType e) {
	//����ҵ��ͷ���λ�򣬷��򷵻�0
	ElemType i, *p;
	i = 1;
	p = L.elem;
	while (i <= L.length && !EQ(*p++ ,e )){
		i++;
	}
	if (i <= L.length) return i;
	else return 0;
}

//��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
//�鲢La��Lb�ĵ��µ�LcҲ�Ƿǵݼ�����
void MergeList_Sq(SqList La , SqList Lb ,SqList &Lc) {
	ElemType *pa,*pb,*pc;
	pa = La.elem; pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType*)malloc(Lc.listsize*sizeof(ElemType));
	if (!Lc.elem)exit(OVERFLOW);
	ElemType *pa_last, *pb_last;
	pa_last = La.elem + La.length-1;
	pb_last = Lb.elem + Lb.length-1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa<=pa_last) *pc++ = *pa++;
	while (pb<=pb_last) *pc++ = *pb++;
}

//���˳���
void PrintSqList(SqList list) {
	cout << "˳���Ϊ��";
	for (int i = 0; i < list.length ; i++) {
		if (i == list.length - 1) cout << list.elem[i];
		else cout << list.elem[i] << ",";
	}
	cout << endl;
}

