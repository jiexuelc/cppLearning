/*************************************************************************
	> File Name: deque.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Sun 10 Jun 2018 09:06:06 PM CST
	> Description: dequec的个性
 ************************************************************************/
/*
 * 1.是用多个vector来实现的
 * 2.双端队列：两端都适合插入和删除
 * 3.下标[]：.operator[](i)不检查越界，.at(i)检查越界并抛出异常
 * 4.支持从前面插入和删除数据：.push_front(element)，.pop_front()
 */

#include<iostream>
#include "print.h"
#include <deque>
using namespace std;

int main()
{
	deque<char> dc;
	dc.push_back(97);dc.push_back('w');
	dc.push_front('a');dc.push_front('n');
	dc.push_back('g');dc.push_front('*');
	print(dc.begin(),dc.end());
	dc[0] = '#';
	for(int i = 0; i<dc.size(); i++)
		cout << dc.at(i) << ' ';
	cout << endl;
	dc.pop_front();
	dc.pop_back();
	print(dc.begin(),dc.end());
	
	return 0;
}