/*************************************************************************
	> File Name: special.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Fri 08 Jun 2018 02:56:50 PM CST
	> Description: 特化(实现阶乘)与偏特化
 ************************************************************************/

#include<iostream>
using namespace std;
#include <typeinfo>

template <int n>//模板
class Fact{
public:
	enum { val= Fact<n-1>::val*n};
};

template <>//特化
class Fact<0>{
public:
	enum{val = 1};
};

template<typename T >//模板
class Type{
public:
	static string name()
	{
		return typeid(T).name();
	}
};

template <>//特化
class Type<char>{
public:
	static string name()
	{
		return "char";
	}
};

template <>//特化
class Type<int>{
public:
	static string name()
	{
		return "int";
	}
};

template <>//特化
class Type<bool>{
public:
	static string name()
	{
		return "bool";
	}
};

template <class T>//偏特化
class Type<T*>{
public:
	static string name()
	{
		return Type<T>::name() + " pointer";
	}
};

int main()
{
	cout << Fact<8>::val << endl;
	cout << Type <char>::name() << endl;
	cout << Type <int>::name() << endl;
	cout << Type <int*>::name() << endl;
	cout << Type <bool**>::name() << endl;
	return 0;
}