/*************************************************************************
	> File Name: CharStrNameComp.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Sun 16 Sep 2018 00:49:03 CST
	> Description: char字符串地址比较
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    char a[] = "abc";
    char b[] = "abc";

    const char c[] = "abc";
    const char d[] = "abc";

    char* e = "abc";
    char* f = "abc";

    const char* g = "abc";
    const char* h = "abc";

    cout << (a == b) << endl;   //true
    cout << (c == d) << endl;   //true
    cout << (e == f) << endl;   //false
    cout << (g == h) << endl;   //false

    return 0;
}
