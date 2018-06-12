/*************************************************************************
	> File Name: multiset.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Tue 12 Jun 2018 04:29:07 PM CST
	> Description:　multiset的个性:本例用其实现统计选票,并按选票排名
 ************************************************************************/
/*
 * 1.元素就是key
 * 2.允许重复的key
 */

#include<iostream>
#include <set>
using namespace std;
#include "print.h"
#include <string>
#include <map>

int main()
{
	multiset<string> ms;
	string name;
	cout << "请输入你要选举人的姓名(以ctrl+D结束)：\n";
	while(cin >> name)
		ms.insert(name);
	print(ms.begin(),ms.end());
	
	multiset<string>::iterator ib = ms.begin(), ie;
	multimap<int,string> mis;//创建一个新的容器
	while(ib != ms.end()){
		mis.insert(make_pair(ms.count(*ib),*ib));//统计与插入到新容器
		ib = ms.upper_bound(*ib);
	}
	print(mis.begin(),mis.end());
	
	return 0;
}
