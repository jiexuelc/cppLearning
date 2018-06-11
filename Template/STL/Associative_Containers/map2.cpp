/*************************************************************************
	> File Name: map2.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Mon 11 Jun 2018 08:51:15 PM CST
	> Description:　map的个性,用自定义类实例化
 ************************************************************************/
/*
 * 1.不允许key重复
 * 2.元素是key/value对
 * 3.支持以key为下标访问对应的value的引用，如果key不存在就新增一个元素以这个为key
 * 4.只关心key，对value不同不管 
 */

#include<iostream>
#include <map>
#include "print.h"
using namespace std;

class Person{//这里的class改为struct一样可以的
	string name;
	int age;
public:
	Person(){}//无参构造函数，不写编译过不去
	Person(const char* name, int age):name(name),age(age){}
	friend ostream& operator<<(ostream& o,const Person& a)
	{
		return o << a.name << ':' << a.age;
	}
	friend bool operator<(const Person& a, const Person& b)
	{
		return a.age < b.age || a.age == b.age && a.name < b.name;
	}
};

int main()
{
	map<int,Person> mis;//会调用无参构造函数建立对象
	mis.insert(map<int,Person>::value_type(2,Person("lichao",24)));//插入
	mis.insert(pair<int,Person>(5,Person("wanglin",22)));
	mis.insert(make_pair(7,Person("jiexue",25)));
	mis[9] = Person("lilin",21);
	mis[13] = Person("limao",22);
	mis[15] = Person("lichun",23);
	mis.insert(make_pair(23,Person("liranchun",23)));
	print(mis.begin(),mis.end(),'\n');//输出，需要重载<<符号
	return 0;
}
