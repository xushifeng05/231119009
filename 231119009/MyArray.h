#pragma once
#include"global.h"
#include<iomanip>

#define MAXSIZE 100
#define ElemType int

static int count1 = 0;
static int count2 = 0;

typedef struct
{
	int i; //行
	int j; //列
	ElemType e; //值
}Triple;

typedef struct
{
	Triple data[MAXSIZE + 1];
	int mu, nu, tu; //行、列 、非零数
}TSMatrix;

void addTriple(TSMatrix &M , Triple T) {
	M.tu++;
	M.data[M.tu].i = T.i;
	M.data[M.tu].j = T.j;
	M.data[M.tu].e = T.e;
}

//矩阵的初始化
void CreateSMatrix(TSMatrix &M){
	M.mu = 6;
	M.nu = 7;
	M.tu = 0;
	addTriple(M, {1 , 2 , 12});
	addTriple(M, {1 , 3 , 9});
	addTriple(M, {3 , 1 , -3});
	addTriple(M, {3 , 6 , 14});
	addTriple(M, {4 , 3 , 24});
	addTriple(M, {5 , 2 , 18});
	addTriple(M, {6 , 1 , 15});
	addTriple(M, {6 , 4 , -7});
}

//普通转置
void TransposeSMatrix(TSMatrix M , TSMatrix &T) {
	int p, q, col;
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu)
	{
		q = 1;
		for ( col = 1; col <= M.nu ; col++)
		{
			for ( p = 1; p < M.tu; p++)
			{
				if (M.data[p].j == col)
				{
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					q++;
				}
				count1++;
			}
		}
	}
	cout << "普通转置的运算次数为：" << count1 << "次" << endl;
}

void FastTransposeSMatrix(TSMatrix M, TSMatrix& T){
	int t, num[100], p, q, col, cpot[100];
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu)
	{
		for ( col = 1; col <= M.nu; col++)
		{
			num[col] = 0;
			count2++;
		}

		for ( t = 1; t <= M.tu; t++)
		{
			num[M.data[t].j]++;
			count2++;
		}
		cpot[1] = 1;
		for ( col = 2; col <= M.nu; col++)
		{
			cpot[col] = cpot[col - 1] + num[col - 1]; //下一行第一该放在位置
			count2++;
		}
		for ( p = 1; p <= M.tu; p++)
		{
			col = M.data[p].j;
			q = cpot[col];
			T.data[q].i = M.data[p].j;
			T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e;
			cpot[col]++;
			count2++;
		}
	}
	cout << "快速转置的运算次数为：" << count2 << "次" << endl;
}

//打印矩阵
void PrintMatrix(TSMatrix M) {
	int p, q, m = 1;
	for ( p = 1; p <= M.mu; p++)
	{
		for ( q = 1; q <= M.nu; q++)
		{
			if (M.data[m].i == p && M.data[m].j == q)
			{
				cout << setw(4) << M.data[m].e;
				m++;
			}
			else
				cout << setw(4) << 0;
			if (q == M.nu)
			{
				cout << endl;
			}
		}
		cout << endl;
	}
}

//稀疏矩阵的十字链表存储表示
//元素结点结构体
typedef struct OLNode {
	int i, j;     //该非零元的行个列的下标
	ELemType e;   //该非零元的值
	struct OLNode* right, * down;
}OLNode, * OLink;

//十字链结构体
typedef struct {
	OLink* rhead, * chead;    //行和列链表头指针向量基址由CreateSMatrix分配
	int mu, nu, tu;
}CrossList , * CrossListn;

//创建稀疏矩阵M，采用十字链表存储表示
CrossList CreateMatrix_OL(CrossList M)
{
	
	int m, n, t;
	int i, j, e;
	OLNode* p, * q;
	//scanf("%d %d %d", &m, &n, &t);
	cin >> m >> n >> t;
	M.mu = m;
	M.nu = n;
	M.tu = t;
	if (!(M.rhead = (OLink*)malloc((m + 1) * sizeof(OLink))) ||
		!(M.chead = (OLink*)malloc((n + 1) * sizeof(OLink))))
	{
		printf("初始化矩阵失败");
		exit(0);
	}
	for (i = 1; i <= m; i++)
	{
		M.rhead[i] = NULL;
	}
	for (j = 1; j <= n; j++)
	{
		M.chead[j] = NULL;
	}
	for (cin >> i >> j >> e; 0 != i; cin >> i >> j >> e)
	{
		if (!(p = (OLNode*)malloc(sizeof(OLNode))))
		{
			printf("初始化三元组失败");
			exit(0);
		}
		p->i = i;
		p->j = j;
		p->e = e;
		if (NULL == M.rhead[i] || M.rhead[i]->j > j)
		{
			p->right = M.rhead[i];
			M.rhead[i] = p;
		}
		else
		{
			for (q = M.rhead[i]; (q->right) && q->right->j < j; q = q->right);
			p->right = q->right;
			q->right = p;
		}
		if (NULL == M.chead[j] || M.chead[j]->i > i)
		{
			p->down = M.chead[j];
			M.chead[j] = p;
		}
		else
		{
			for (q = M.chead[j]; (q->down) && q->down->i < i; q = q->down);
			p->down = q->down;
			q->down = p;
		}
	}

	return M;
}

void display(CrossList M)
{
	printf("输出测试矩阵:\n");
	printf("M:\n---------------------\ni\tj\te\n---------------------\n");
	for (int i = 1; i <= M.nu; i++)
	{
		if (NULL != M.chead[i])
		{
			OLink p = M.chead[i];
			while (NULL != p)
			{
				printf("%d\t%d\t%d\n", p->i, p->j, p->e);
				p = p->down;
			}
		}
	}
}

CrossList AddSMatrix(CrossList M, CrossList N)
{
	OLNode* pa, * pb;   //新增的两个用于遍历两个矩阵的结点
	OLink* hl = (OLink*)malloc(M.nu * sizeof(OLink));
	OLNode* pre = NULL;
	//遍历初期，首先要对hl数组进行初始化，指向每一列的第一个非0元素
	for (int j = 1; j <= M.nu; j++)
	{
		hl[j] = M.chead[j];
	}
	//按照行进行遍历
	for (int i = 1; i <= M.mu; i++)
	{
		//遍历每一行以前，都要pa指向矩阵M当前行的第一个非0元素；指针pb也是如此，只不过遍历对象为矩阵N
		pa = M.rhead[i];
		pb = N.rhead[i];
		//当pb为NULL时，说明矩阵N的当前行的非0元素已经遍历完。
		while (pb != NULL)
		{
			//创建一个新的结点，每次都要复制一个pb结点，但是两个指针域除外。（复制的目的就是排除指针域的干扰）
			OLNode* p = (OLNode*)malloc(sizeof(OLNode));
			p->i = pb->i;
			p->j = pb->j;
			p->e = pb->e;
			p->down = NULL;
			p->right = NULL;
			//第一种情况
			if (pa == NULL || pa->j > pb->j)
			{
				//如果pre为NULL，说明矩阵M此行没有非0元素
				if (pre == NULL)
				{
					M.rhead[p->i] = p;
				}
				else
				{
					//由于程序开始时pre肯定为NULL，所以，pre指向的是第一个p的位置，在后面的遍历过程中，p指向的位置是逐渐向后移动的，所有，pre肯定会在p的前边
					pre->right = p;
				}
				p->right = pa;
				pre = p;
				//在链接好行链表之后，链接到对应列的列链表中的相应位置
				if (!M.chead[p->j] || M.chead[p->j]->i > p->i)
				{
					p->down = M.chead[p->j];
					M.chead[p->j] = p;
				}
				else
				{
					p->down = hl[p->j]->down;
					hl[p->j]->down = p;
				}
				//更新hl中的数据
				hl[p->j] = p;
			}
			else
			{
				//第二种情况，只需要移动pa的位置，继续判断pa和pb的位置，一定要有continue
				if (pa->j < pb->j)
				{
					pre = pa;
					pa = pa->right;
					continue;
				}
				//第三、四种情况，当行标和列标都想等的情况下，需要讨论两者相加的值的问题
				if (pa->j == pb->j)
				{
					pa->e += pb->e;
					//如果为0，摘除当前结点，并释放所占的空间
					if (pa->e == 0)
					{
						if (pre == NULL)
						{
							M.rhead[pa->i] = pa->right;
						}
						else
						{
							pre->right = pa->right;
						}
						p = pa;
						pa = pa->right;
						if (M.chead[p->j] == p)
						{
							M.chead[p->j] = hl[p->j] = p->down;
						}
						else
						{
							hl[p->j]->down = p->down;
						}
						free(p);
					}
				}
			}
			pb = pb->right;
		}
	}
	//用于输出矩阵三元组的功能函数

	return M;
}

