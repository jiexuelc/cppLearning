/*************************************************************************
	> File Name: pair.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Sat 09 Jun 2018 06:00:34 PM CST
	> Description:多个类参数的类模板，利用函数实例化类模板
 ************************************************************************/

#include<iostream>
#include <cstdlib>
using namespace std;

template <typename To, typename From>
To convert2(From a)
{
	return To(a);
}

template <typename To>
To convert2(const char* str)
{
	return To(atoi(str));
}

template <typename T, typename U>
struct Pair{
	T first;
	U second;
	Pair():first(),second(){}
	Pair(const T& a, const U& b):first(a),second(b){}
	template <typename X, typename Y>//类模板里面还可以有模板
	Pair& operator=(const Pair<X,Y>& a)
	{
		first = convert2<T>(a.first);
		second = convert2<U>(a.second);
		return *this;
	}
};

template <typename T, typename U>
ostream& operator<<(ostream& o, const Pair<T,U>& p)
{
	return o << p.first << '/' << p.second;
}

template <typename T, typename U>
Pair<T,U> mp(const T a, const U b)//用函数模板识别类型并自动实例化类模板
{
	Pair<T,U> obj(a,b);
	return obj;
	//前两行可以合并写成　return Pair<T,U> (a,b);
}

int main()
{
	cout << Pair<const char*,int>("lichao",25) << endl;
	cout << Pair<int,const char*>(22,"wanglin") << endl;
	cout << mp("lichao",25) << endl;
	cout << mp(22,"wanglin") << endl;
	Pair<int,double> a(22,87.5);
	cout << a << endl;
	a = mp("22","25");
	cout << a << endl;
	return 0;
}