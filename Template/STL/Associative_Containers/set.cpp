/*************************************************************************
	> File Name: set.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Mon 11 Jun 2018 09:34:22 PM CST
	> Description:　set的个性:本例去除重复的邮箱
 ************************************************************************/
/*
 * 1.元素就是key
 * 2.不允许重复的key
 */

#include<iostream>
#include <set>
using namespace std;
#include <string>
#include "print.h"
#include <fstream>

int main()
{
	set<string> ss;
	string s;
	ifstream fin("maillist");
	if(!fin) return 1;
	while(fin >> s) ss.insert(s);
	print(ss.begin(),ss.end(),'\n');
	
	return 0;
}
