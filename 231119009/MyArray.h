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