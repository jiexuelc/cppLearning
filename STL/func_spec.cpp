/*************************************************************************
	> File Name: func_spec.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Fri 08 Jun 2018 03:20:32 PM CST
	> Description: 函数模板、实例化、通过函数实例化类模板
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
class Type<double>{
public:
	static string name()
	{
		return "double";
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

template <typename T >
string fun_type(T t)
{
	return Type<T>::name();
}

int main()
{
	cout << fun_type(123) << endl;
	cout << fun_type(45.6) << endl;
	cout << fun_type('a') << endl;
	int a = 50;
	char b = 'z';
	cout << fun_type(&a) << endl;
	cout << fun_type(a < b) << endl;
	cout << fun_type(a/1.0) << endl;
	return 0;
}