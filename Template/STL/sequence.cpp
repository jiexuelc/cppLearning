/*************************************************************************
	> File Name: sequence.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Sun 10 Jun 2018 10:41:40 AM CST
	> Description: 序列式容器共性
 ************************************************************************/
/*
 * vector、deque、list
 * 都包含有容器的共性
 * 增加的：
 * 	1.构造函数：指定个数和初始值(初始值默认为零初始化)
 *	2.插入：.insert(pos, n, element)在指定位置插入指定个数的元素，.insert(pos, pos_beg, pos_end)把一个区间的元素插入到指定位置
 * 	3.赋值(旧的清除掉)：.assign(n, element)n个相同的值，.assign(pos_beg, pos_end)把某个区间的值给当前对象
 * 	4.调整：.resize(n, element)element默认零初始化
 * 	5.首尾：.front()、.back()
 * 	6.支持在末尾插入和删除数据.push_back(element)，.pop_back()(只负责删除数据，不负责带回数据，返回void)
 */

#include<iostream>
#include<algorithm>
#include<deque>
#include "print.h"
#include<string>
using namespace std;

int main()
{
	deque<string> ds;
	ds.push_back("lichao");ds.push_back("wanglin");ds.push_back("limao");ds.push_back("liranchun");ds.push_back("liranlong");
	print(ds.begin(),ds.end(),'\n');
	ds.insert(++++ds.begin(),2,"lilin");//插入
	print(ds.begin(),ds.end(),'\n');
	string s[3] = {"容器","末尾","开始"};
	print(ds.begin(),ds.end(),' ');
	ds.insert(ds.begin(),s,s+3);
	sort(ds.begin(),ds.end());
	print(ds.begin(),ds.end(),' ');
	ds.pop_back();ds.pop_back();
	print(ds.begin(),ds.end(),' ');
	cout << "front:" << ds.front() << " back:" << ds.back() << endl;
	ds.resize(12,"jiexue");//重新调整的超出队列的用jiexue初始化
	print(ds.begin(),ds.end(),' ');
	ds.assign(3,"lichao");//赋值
	print(ds.begin(),ds.end(),' ');
	ds.front() = "wanglin";
	ds.back() = "jiexue";
	print(ds.begin(),ds.end(),' ');
	return 0;
}