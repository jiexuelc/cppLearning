/*************************************************************************
	> File Name: associate.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Mon 11 Jun 2018 03:40:42 PM CST
	> Description: 关联式(associate)容器共性
 ************************************************************************/
/*
 * 关联式容器：set<K>、multiset<K>、map<K,V>、mutimap<K,V>
 * 关联式容器又叫字典
 * 1.都是用二叉查找树实现的，都自动根据关键字排序(默认升序)
 * 2.查找：.find(key)返回指向找到第一个元素的迭代器，倘若没找到，返回指向无效位置的迭代器.end()
 * 3.统计：.count(key)统计关键字等于key元素的个数
 * 4.删除：.erase(key)删除关键字等于key的所有元素
 * 5.区间：.lower_bound(key)取得关键字为key的第一个元素的位置, .upper_bound(key)取得关键字为key的最后一个元素之后的位置， .equal_range(key)一次取得关键字为key的元素的区间，返回一个pair
 * 6.插入：.insert(element)不用指定位置，自然会找到合适的位置
 * 7.构造函数：可以用比较函数作为参数bool compare(K a, K b)
 */

#include <iostream>
#include <set>
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
	multiset <Person> mp;//实例化
	mp.insert(Person("lichao",24));//插入
	mp.insert(Person("wanglin",22));
	mp.insert(Person("wanglin",22));
	mp.insert(Person("lichao",24));
	mp.insert(Person("wanglin",22));
	mp.insert(Person("limao",22));
	mp.insert(Person("lilin",21));
	mp.insert(Person("liranchun",23));
	mp.insert(Person("liranlong",30));
	print(mp.begin(),mp.end());//输出
	multiset<Person>::iterator it = mp.find(Person("lichao",24));//搜索
	if(it == mp.end()) cout << "Can not find: lichao" << endl;
	else cout << "finding:" << *it << endl;
	it = mp.find(Person("jiexue",22));
	if(it == mp.end()) cout << "Can not find: jiexue" << endl;
	else cout << "finding:" << *it << endl;
	it = mp.find(Person("wanglin",22));
	if(it == mp.end()) cout << "Can not find: wanglin" << endl;
	else cout << "finding:" << mp.count(*it) << "个" << *it << endl;
	
	multiset<Person>::iterator ib, ie;
	ib = mp.lower_bound(Person("wanglin",22));//取得第一个位置
	ie = mp.upper_bound(*it);//取得最后一个元素之后的位置
	print(ib,ie);
	pair<multiset<Person>::iterator, multiset<Person>::iterator> p = mp.equal_range(Person("lichao",24));//获得一个区间
	print(p.first,p.second);
	
	mp.erase(*it);//删除所有等于*it的元素
	mp.erase(Person("lichao",24));
	print(mp.begin(),mp.end());
	
	return 0;
}