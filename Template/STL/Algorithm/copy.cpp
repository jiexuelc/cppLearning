/*************************************************************************
	> File Name: copy.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Tue 12 Jun 2018 10:20:39 PM CST
	> Description: 算法copy
 ************************************************************************/
/*
 * 1.算法操作的目标是迭代器
 * 2.for_each(pos_beg,pos_end,func)
 * 3.copy(pos_beg,pos_end,a)正序复制
 * 4.copy_backward(pos_beg,pos_end,a)倒序复制，适合目标区域和原区域有重叠的情况
 * 5.iterator find(pos_beg, pos_end, data)、iterator find_if(pos_beg, pos_end, cond), bool cond(element)
 * 6.int count(...), int count_if(...)
 */

#include<iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include "print.h"
using namespace std;

//模拟标准库复制算法
template <class Iter, class Pos>
void co(Iter ib,Iter ie, Pos p)
{
	while(ib != ie) *p++ = *ib++;
}

//模拟标准库倒序复制算法
template <class Iter, class Pos>
void co_back(Iter ib,Iter ie, Pos p)
{
	while(ib != ie) *--p = *--ie;
}

//判断是否奇数
bool func(int n){return n & 1;}

int main()
{
	int a[5] = {50,30,90,20,40};
	int b[8] = {0};
	vector<int> vi(a,a+5);
	print(vi.begin(),vi.end());
	sort(vi.begin(),vi.end());
	print(vi.begin(),vi.end());
	copy(vi.begin(),vi.end(),b);
	print(b,b+8);
	
	co(vi.begin(),vi.end(),a);//自写复制函数模拟标准复制函数
	print(a,a+5);
	
	copy_backward(b,b+5,b+8);//倒序复制
	print(b,b+8);
	deque<int> v;
	//back_inserter(v)把对元素的赋值变成后插入
	//因为v一开始为空，不能将其复制到一个空deque
	co(a,a+5,back_inserter(v));
	print(v.begin(),v.end());
	co(a,a+5,front_inserter(v));//前插
	print(v.begin(),v.end());
	v.clear();
	int c[8] = {1,2,3,4,5,6,7,8};
	remove_copy_if(c,c+8,back_inserter(v),func);//将不满足函数func的复制到v里面
	print(v.begin(),v.end());
	
	return 0;
}
