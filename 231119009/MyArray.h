#pragma once
#include"global.h"
#include<iomanip>

#define MAXSIZE 100
#define ElemType int

static int count1 = 0;
static int count2 = 0;

typedef struct
{
	int i; //��
	int j; //��
	ElemType e; //ֵ
}Triple;

typedef struct
{
	Triple data[MAXSIZE + 1];
	int mu, nu, tu; //�С��� ��������
}TSMatrix;

void addTriple(TSMatrix &M , Triple T) {
	M.tu++;
	M.data[M.tu].i = T.i;
	M.data[M.tu].j = T.j;
	M.data[M.tu].e = T.e;
}

//����ĳ�ʼ��
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

//��ͨת��
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
	cout << "��ͨת�õ��������Ϊ��" << count1 << "��" << endl;
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
			cpot[col] = cpot[col - 1] + num[col - 1]; //��һ�е�һ�÷���λ��
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
	cout << "����ת�õ��������Ϊ��" << count2 << "��" << endl;
}

//��ӡ����
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

//ϡ������ʮ������洢��ʾ
//Ԫ�ؽ��ṹ��
typedef struct OLNode {
	int i, j;     //�÷���Ԫ���и��е��±�
	ELemType e;   //�÷���Ԫ��ֵ
	struct OLNode* right, * down;
}OLNode, * OLink;

//ʮ�����ṹ��
typedef struct {
	OLink* rhead, * chead;    //�к�������ͷָ��������ַ��CreateSMatrix����
	int mu, nu, tu;
}CrossList , * CrossListn;

//����ϡ�����M������ʮ������洢��ʾ
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
		printf("��ʼ������ʧ��");
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
			printf("��ʼ����Ԫ��ʧ��");
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
	printf("������Ծ���:\n");
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
	OLNode* pa, * pb;   //�������������ڱ�����������Ľ��
	OLink* hl = (OLink*)malloc(M.nu * sizeof(OLink));
	OLNode* pre = NULL;
	//�������ڣ�����Ҫ��hl������г�ʼ����ָ��ÿһ�еĵ�һ����0Ԫ��
	for (int j = 1; j <= M.nu; j++)
	{
		hl[j] = M.chead[j];
	}
	//�����н��б���
	for (int i = 1; i <= M.mu; i++)
	{
		//����ÿһ����ǰ����Ҫpaָ�����M��ǰ�еĵ�һ����0Ԫ�أ�ָ��pbҲ����ˣ�ֻ������������Ϊ����N
		pa = M.rhead[i];
		pb = N.rhead[i];
		//��pbΪNULLʱ��˵������N�ĵ�ǰ�еķ�0Ԫ���Ѿ������ꡣ
		while (pb != NULL)
		{
			//����һ���µĽ�㣬ÿ�ζ�Ҫ����һ��pb��㣬��������ָ������⡣�����Ƶ�Ŀ�ľ����ų�ָ����ĸ��ţ�
			OLNode* p = (OLNode*)malloc(sizeof(OLNode));
			p->i = pb->i;
			p->j = pb->j;
			p->e = pb->e;
			p->down = NULL;
			p->right = NULL;
			//��һ�����
			if (pa == NULL || pa->j > pb->j)
			{
				//���preΪNULL��˵������M����û�з�0Ԫ��
				if (pre == NULL)
				{
					M.rhead[p->i] = p;
				}
				else
				{
					//���ڳ���ʼʱpre�϶�ΪNULL�����ԣ�preָ����ǵ�һ��p��λ�ã��ں���ı��������У�pָ���λ����������ƶ��ģ����У�pre�϶�����p��ǰ��
					pre->right = p;
				}
				p->right = pa;
				pre = p;
				//�����Ӻ�������֮�����ӵ���Ӧ�е��������е���Ӧλ��
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
				//����hl�е�����
				hl[p->j] = p;
			}
			else
			{
				//�ڶ��������ֻ��Ҫ�ƶ�pa��λ�ã������ж�pa��pb��λ�ã�һ��Ҫ��continue
				if (pa->j < pb->j)
				{
					pre = pa;
					pa = pa->right;
					continue;
				}
				//������������������б���б궼��ȵ�����£���Ҫ����������ӵ�ֵ������
				if (pa->j == pb->j)
				{
					pa->e += pb->e;
					//���Ϊ0��ժ����ǰ��㣬���ͷ���ռ�Ŀռ�
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
	//�������������Ԫ��Ĺ��ܺ���

	return M;
}

