/*************************************************************************
	> File Name: D_list.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Sun 10 Jun 2018 09:17:15 PM CST
	> Description: 双向list的个性
 ************************************************************************/
/*
 * 1.双向链表
 * 2.在前面插入及删除：.push_front()前面插入，.pop_front()前端删除，.remove(element)删除等于指定元素值的所有元素(需要支持==符号)
 * 3.除重：.unique()去除相邻的重复元素，只保留一个(不影响不相邻的)
 * 4.排序：.sort(compare_func=less)默认用小于函数，需要时需要重载“<”运算符
 * 5.倒置：.reverse()颠倒链表中元素顺序
 * 6.转移：.splice(pos,list2)将另外一个同类链表转移过来，.splice(pos, list2,pos2)，.splice(pos,list2,pos_beg,pos_end)
 * 7.归并：.merge(list2)将另外一个链表归并过来(前提是两组已经排好序的list，最后才是排好序的)
 */

#include<iostream>
#include <list>
#include <cassert>
#include "print.h"
using namespace std;
bool compare(int x, int y)
{
	x %= 5; y %= 5;
	return x < y;
}

int main()
{
	int ai1[10] = {5,7,7,9,10,10,7,3,2,1}, ai2[6] = {9,4,6,5,8,7};
	list<int> li1(ai1,ai1+10), li2(ai2,ai2+6);
	print(li1.begin(),li1.end());
	li1.unique();//唯一化
	print(li1.begin(),li1.end());
	li1.sort();//从小到大排序
	print(li1.begin(),li1.end());
	li1.unique();
	print(li1.begin(),li1.end());
	li1.reverse();//翻转
	print(li1.begin(),li1.end());
	li1.splice(li1.end(),li2);//转移li2
	print(li1.begin(),li1.end());
	assert(li2.empty());//断言li2为空,如果不为空会出现错误
	li1.remove(5);//移除所有５
	print(li1.begin(),li1.end());
	li1.sort();li1.unique();
	print(li1.begin(),li1.end());
	li2.push_back(9);li2.push_front(7);li2.push_back(10);
	li2.push_front(5);li2.push_front(3);li2.push_front(0);
	li2.sort();
	print(li2.begin(),li2.end());
	li1.merge(li2);//将排好序的两个list归并
	print(li1.begin(),li1.end());
	li2.assign(ai2,ai2+6);
	print(li2.begin(),li2.end());
	li2.sort(greater<int>());//标准库自带的>关系
	print(li2.begin(),li2.end());
	li2.sort(compare);//比较函数可自己定义
	print(li2.begin(),li2.end());
	
	return 0;
}