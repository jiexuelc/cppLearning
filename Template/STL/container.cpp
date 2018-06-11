/*************************************************************************
	> File Name: container.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Sun 10 Jun 2018 09:52:19 AM CST
	> Description:　标准容器的使用
 ************************************************************************/
/*
 * 标准容器（类模板）的共性：vector,deque,list,set/map,multi...
 * 1.构造函数：无参构造、拷贝构造、区间构造(两个迭代器表示的两个位置[))
 * 2.析构函数
 * 3.迭代器相关：
 *	.begin()返回指向第一个元素的迭代器，.end()返回指向超越最后一个位置的迭代器，.rbegin()返回指向反向第一个元素的迭代器，.rend()返回指向反向最后一个位置的迭代器；
 *	类型：iterator，reverse_iterator，const_iterator，const_reverse_iterator；
 *	支持运算符：*、->、 =、 ++、 ==、 != 、--
 * 4.插入：.insert(pos,element)，其中pos表示插入位置，是个迭代器
 * 5.删除：.erase(pos)，.erase(pos_begin,pos_end)
 * 6.清除：.clear()
 * 7.大小：.size()，.max_size()，.empty()，
 * 8.交换：.swap(c2)，swap(c1,c2)(如果有专用的算法，尽量使用为类量身定做的算法，因为这样子效率最高)
 * 9.支持运算符：=、>、 <、 >=、 <=、 ==、 !=
 * 
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include "print.h"
using namespace std;

int main()
{
	int ai[10] = {10,9,8,7,6,5,4,3,2,1};
	vector<int> vi(ai,ai+10);//新建与初始化
	cout << vi.size() << endl;
	sort(vi.begin(),vi.end());//只能是数组、vector、deque
	print(ai,ai+10);
	vector<int>::iterator b = vi.begin();//迭代器
	while(b != vi.end())
		cout << *b++ << ' ';
	cout << endl;
	print(vi.begin(),vi.end());//正向输出
	print(vi.rbegin(),vi.rend());//逆向输出
	b = vi.begin();
	vi.insert(++++b,12);//插入
	vi.insert(vi.end(),20);
	print(vi.begin(),vi.end());
	cout << vi.size() << '/' << vi.max_size() << endl;
	vi.erase(------vi.end());//删除
	vi.erase(++++++vi.begin());
	print(vi.begin(),vi.end());
	
	vector<int> vi1(ai,ai+5);
	vector<int> vi2(ai+4,ai+10);
	vi1.swap(vi2);//交换
	print(vi1.begin(),vi1.end());
	print(vi2.begin(),vi2.end());
	swap(vi1,vi2);
	print(vi1.begin(),vi1.end());
	print(vi2.begin(),vi2.end());
	
	vector<int> temp = vi1;//赋值
	vi1 = vi2;
	vi2 = temp;
	print(vi1.begin(),vi1.end());
	print(vi2.begin(),vi2.end());
	
	vi1.clear();vi2.clear();//清除数据
	print(vi1.begin(),vi1.end());
	print(vi2.begin(),vi2.end());
	
	vector<int> vi3;
	cout << "vector当前容量：" << vi3.capacity() << endl;//只有vector有当前容量
	return 0;
}