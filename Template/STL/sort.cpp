/*************************************************************************
	> File Name: sort.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Sat 09 Jun 2018 09:38:21 PM CST
	> Description: 标准模板库sort算法排序，其他自定义类型需要重载<符号
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include "print.h"
using namespace std;

class Person{
	string name;
	int age;
public:
	Person(const char* name, int age):name(name),age(age){}
	friend ostream& operator<<(ostream& o,const Person& a)
	{
		return o << a.name << '/' << a.age;
	}
	friend bool operator<(const Person& a, const Person& b)
	{
		return a.age < b.age || a.age == b.age && a.name < b.name;
	}
};

int main()
{
	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	sort(a,a+10);
	print(a,a+10);
	string str[5] = {"I","want","to","study","programming"};
	sort(str,str+5);
	print(str,str+5);
	Person p[5] = {Person("lichao",25),Person("wanglin",22),Person("liranchun",22),Person("limao",21),Person("liranlong",31)};
	sort(p,p+5);
	print(p,p+5);
	return 0;
}