/*************************************************************************
	> File Name: print.h
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Wed 06 Jun 2018 09:55:47 PM CST
	> Description: 打印输出模板
 ************************************************************************/

#ifndef _PRINT_H
#define _PRINT_H
using namespace std;
template<typename T>
void print(T a, char ch = ' ')
{
	while(!a.empty())
		cout << a.pop() << ch;
	cout << endl;
}

#endif
