/*************************************************************************
	> File Name: for_ench.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Tue 12 Jun 2018 09:53:23 PM CST
	> Description: 算法for-each
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
#include <algorithm>
using namespace std;

void add10(int& element)
{
	element += 10;
}

class Add{
	int delta;
public:
	Add(int d):delta(d){}
	void operator()(int& element){
		element += delta;
	}
};

void print(int& element)
{
	cout << element << ' ';
}

template <typename Iter, typename Func>
void foreach(Iter ib, Iter ie, Func f)//模拟for_each()的实现
{
	while(ib != ie) f(*ib++);
}

int main()
{
	int a[5] = {10,20,30,40,50};
	for_each(a,a+5,add10);
	for_each(a,a+5,print); cout << endl;
	for_each(a,a+5,Add(-10));//匿名对象实现
	for_each(a,a+5,print); cout << endl;
	
	foreach(a,a+5,Add(2));
	for_each(a,a+5,print); cout << endl;
	foreach(a,a+5,Add(-2));
	for_each(a,a+5,print); cout << endl;
	
	return 0;
}
