#include "global.h"
#include<string>

#define MAXSTRLEN 80

//定长顺序分配
typedef struct {
	unsigned char data[MAXSTRLEN + 1];
	int length;
}SString;

//堆分配
typedef struct {
	char* ch;
	int length;
}HString;

//串的块链存储
typedef struct Chunk {
	char ch[MAXSTRLEN];
	struct Chunk* next;
};

typedef struct {
	Chunk* head, * tail;
	int curlen;
}LSting;

//通过一个字符数组cstr来构建一个SString
Status StrAssign(SString &s,char cstr[]) {
	int i;
	for ( i = 1; cstr[i - 1] != '\0' ; i++)
	{
		if (i > MAXSTRLEN) return ERROR;
		s.data[i] = cstr[i - 1];
	}
	s.length = i - 1;
	cout << "字符长度为：" << s.length << endl;
	return OK;
}

//字符串的输出
Status StrOutPut(SString s) {
	int i;
	cout << "串的元素为：";
		for ( i = 1; i <= s.length; i++)
		{
			cout << s.data[i] << ",";
		}
	cout << endl;
	return OK;
}

//字符串的拼接
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

//返回需要的子字符串
Status SubString(SString &Sub , SString S, int pos , int len) {
	int i;
	if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
		return ERROR;
	for (i = 1; i <= len; i++)
		Sub.data[i] = S.data[pos + i - 1];
	Sub.length = len;
	return OK;
}

//串的长度
Status GetStrLength(SString S) {
	return S.length;
}

//清除串
Status ClearStr(SString &S) {
	int i;
	for ( i = 1; i < S.length; i++)
	{
		S.data[i] = '\0';
		S.length = 0;
		return OK;
	}
}

//判断串是否为空
Status StrIsEmpty(SString S) {
	if (S.length == 0)
		return OK;
	else
		return ERROR;
}

//将串S复制给T
Status StrCopy(SString &T,SString S) {
	int i;
	for ( i = 0; i < S.length; i++)
	{
		T.data[i] = S.data[i];
	}
	return OK;
}

//查询子串，BF算法
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

//判断串是否相等
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

//串的插入
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

//串的删除
Status StrDelete(SString &S , int pos , int len) {
	int i;
	if (pos<1 || pos>S.length || len<0 || len>S.length - pos + 1)
		return ERROR;
	for ( i = pos; i < S.length-pos-len; i++)
	{
		S.data[i] = S.data[i + len];
	}
	S.length = S.length - len;
	return OK;
}

//销毁串
Status DestroyStr(SString &S) {
	int i;
	for (i = MAXSTRLEN; i >= 0; i--)
		free(S.data + i);
	return OK;
}

//kmp的next数组
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
	cout << "模式串的next数组为：";
	for ( j = 1; j < i; j++)
	{
		cout << next[j] << ",";
	}
	cout << endl;
}

//kmp算法
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

//稀疏矩阵的十字链表存储表示
//元素结点结构体
typedef struct OLNode {
	int i, j;     //该非零元的行个列的下标
	ELemType e;   //该非零元的值
	struct OLNode* right, * down;
}OLNode, *OLink;

//十字链结构体
typedef struct {
	OLink *rhead, *chead;    //行和列链表头指针向量基址由CreateSMatrix分配
	int mu, nu, tu;
}CrossList;

//创建稀疏矩阵M，采用十字链表存储表示
Status CreateSMatrix_OL(CrossList &M) {
	if (&M) free(&M);
	int m, n, t;
	int i, j, e;
	OLNode* p;
	OLink q;
	cin >> m >> n >> t;
	M.mu = m; M.nu = n; M.tu = t;
	if (!(M.rhead = (OLink *)malloc((m + 1) * sizeof(OLink))))
		exit(OVERFLOW);
	if (!(M.chead = (OLink *)malloc((n + 1) * sizeof(OLink))))
		exit(OVERFLOW);
	M.rhead = M.chead = NULL;
	for (cin >> i >> j >>e;i!=0;cin >> i >> j>>e)
	{
		if (!(p = (OLNode *)malloc(sizeof(OLNode)))) exit(OVERFLOW);
		p->i = i; p->j = j; p->e = e;    //生成结点
		if (M.rhead[i] == NULL || M.rhead[i]->j > j)
		{
			p->right = M.rhead[i]; M.rhead[i] = p;
		}
		else
		{
			for (q = M.rhead[i];(q->right)&&q->right->j<j;q=q->right)
			{
				p->right = q->right;
				q->down = p;
			}
		}
		if (M.chead[j] == NULL || M.rhead[j]->i > i)
		{
			p->down = M.chead[j]; M.chead[j] = p;
		}
		else
		{
			for (q = M.chead[j]; (q->down) && q->down->i < i; q = q->down)
			{
				p->down = q->down;
				q->down = p;
			}
		}
	}
}