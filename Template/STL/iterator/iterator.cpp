/*************************************************************************
	> File Name: iterator.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Thu 14 Jun 2018 08:03:04 PM CST
	> Description: 迭代器
 ************************************************************************/
/*
 * 迭代器分类（it）：
 * 1.所有迭代器都支持++,*,->,==,!=
 * 2.输入迭代器：可读*it的值，但不一定能修改（设置）*it的值
 * 3.输出迭代器：可以设置*it的值，但不一定能读取*it的值
 * 4.前向迭代器：可以读取也可以设置*it的值
 * 5.双向迭代器：支持--
 * 6.随机迭代器：几乎跟指针一样，支持--,+n,-n,比较大小，[下标]
 * 
 */

#include<iostream>
#include<iterator>
#include<algorithm>
#include "print.h"
#include<vector>
#include<fstream>
using namespace std;

int main()
{
 	istream_iterator<int> in(cin);
	istream_iterator<int> end;
	vector<int> vi;
	copy(in,end,back_inserter(vi));
	print(vi.begin(),vi.end());
	
	ostream_iterator<int> out(cout," ");
	copy(vi.begin(),vi.end(),out);
	cout << endl;
	
	ofstream fo("datafile");
	ostream_iterator<int> fiter(fo," ");
	copy(vi.begin(),vi.end(),fiter);
	fo << endl;
	fo.close();
	
	ifstream fin("datafile");
	istream_iterator<int> fit(fin);
	vector<int> vi2;
	copy(fit,end,back_inserter(vi2));
	print(vi2.begin(),vi2.end(),',');
	
	return 0;
}
