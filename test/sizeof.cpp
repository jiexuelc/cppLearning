/*************************************************************************
	> File Name: sizeof.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Thu 30 May 2018 13:42:11 PM CST
	> Description: c++里面如果一个结构体或者类是空的，则占用char的内存，一旦有成员则按成员占用内存计算
	> Description: C里面如果是空的则就是０
 ************************************************************************/

#include <iostream>
using namespace std;

struct person{
	char ch;
	int i;
};

class A{
	char ch;
	int i;
};

int main()
{
	person a;
	A b;
	cout << sizeof(a) <<endl;
	cout << sizeof(b) <<endl;
	
	return 0;
}
