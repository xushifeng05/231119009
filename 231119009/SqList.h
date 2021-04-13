#include "global.h"

#define ElemType int
#define LISTINCREMENT 10

typedef struct {
	ElemType* elem; //顺序表的基地址
	int listsize; //顺序表的存储容量
	int length; //顺序表的元素个数
}SqList;


//初始化
Status InitList_sq(SqList &L) {
	L.elem = (ElemType*)malloc(100*sizeof(int));//分配存储空间
	if (!L.elem) {
		exit(OVERFLOW);
	}
	L.listsize = 100;
	L.length = 0;
	return OK;
}


//在顺序表尾部增加元素
Status addElem_Sq(SqList &L, ElemType e) {
	L.elem[L.length] = e; //将线性表的最后一个元素赋值为e
	L.length++;
	return OK;
}

//在顺序线性表L中第i个位置之前插入新的元素e
Status ListInsert_Sq(SqList &L , int i , ElemType e) {
	//i的合法值为1<=i<=ListLength_Sq(L)+1
	if (i<1 || i>L.length+1)
	{
		return ERROR;
	}
	if (L.length >= L.listsize) {//当前存储空间已满，增加分配
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
	q = &(L.elem[i - 1]);//q插入的位置
	for (p = &(L.elem[L.length-1]); p >= q ; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	++L.length;
	return OK;
}

//在顺序线性表L中删除第i个元素，并用e返回其值
Status ListDelete_Sq(SqList &L , int i , ElemType &e) {
	//i的合法值为1<=i<=ListLength_Sq(L)
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

//在顺序线性表L中查找第一个值与e满足EQ（）的元素位序
ElemType LocateElem_Sq(SqList L , ElemType e) {
	//如果找到就返回位序，否则返回0
	ElemType i, *p;
	i = 1;
	p = L.elem;
	while (i <= L.length && !EQ(*p++ ,e )){
		i++;
	}
	if (i <= L.length) return i;
	else return 0;
}

//已知顺序线性表La和Lb的元素按值非递减排列
//归并La和Lb的到新的Lc也是非递减排列
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

//输出顺序表
void PrintSqList(SqList list) {
	cout << "顺序表为：";
	for (int i = 0; i < list.length ; i++) {
		if (i == list.length - 1) cout << list.elem[i];
		else cout << list.elem[i] << ",";
	}
	cout << endl;
}

