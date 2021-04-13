#pragma once
#include<stdio.h>
#include<stdlib.h>//C++标准库
#include<iostream>//C++输入输出库
using namespace std;
#define  TRUE    1
#define  FALSE   0
#define  OK    1
#define  ERROR   0
#define  INFERFLOW   -1
#define  OVERFLOW   -2
#define  ELemType      int

#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LQ(a,b) ((a) <= (b))
#define MT(a,b) ((a) > (b))
#define MQ(a,b) ((a) >= (b))

//Status是函数的类型，其值是函数结果状态代码
typedef int Status;