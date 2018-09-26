/*************************************************************************
	> File Name: gVariableAccess.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Wed 26 Sep 2018 04:02:57 PM CST
	> Description: 访问与局部变量同名的全局变量
        使用作用域限定符(::)(scope resolution operator)来区别同名的全局变量
 ************************************************************************/

#include <iostream>
using namespace std;

long long Variable = 2048;

int main()
{
    int Variable = 10;
    
    cout << "局部变量值: " << Variable << endl;
    cout << "全局变量值: " << ::Variable << endl;
    
    return 0;
}