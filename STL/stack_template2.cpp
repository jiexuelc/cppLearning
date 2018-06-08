/*************************************************************************
	> File Name: stack_template2.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Fri 08 Jun 2018 10:19:56 AM CST
	> Description: 模板默认值以及部分特化
 ************************************************************************/

#include<iostream>
#include "print.h"
#include <cstring>
using namespace std;

template <typename T = int,int len = 5>
class Stack{
    T str[len];
    int cur;
public:
    Stack():cur(0){}
    void push(const T& d)throw(const char*)
	{
		//入栈操作
		if(full())throw "full";
		str[cur++] = d;
	}
	
    T& pop()throw(const char*)
	{
		//出栈操作
		if(empty())throw "empty";
		return str[--cur];
	}
	
    const T& top()const
	{
		//获得栈顶元素
		return str[cur-1];
	}
	
    bool empty()const
	{
		//判断栈是否为空
		return cur == 0;
	}
    
    void clear(){cur = 0;}
    bool full()const
	{
		//判断栈是否满
		return cur == len;
	}
};

//部分特化
template <int len>
class Stack<const char*,len>{
    string str[len];
    int cur;
public:
    Stack():cur(0){}
    void push(const char* d)throw(const char*)
	{
		//入栈操作
		if(full())throw "full";
		str[cur++] = d;
	}
	
    const char* pop()throw(const char*)
	{
		//出栈操作
		if(empty())throw "empty";
		return str[--cur].c_str();
	}
	
    const char*& top()const
	{
		//获得栈顶元素
		return str[cur-1].c_str();
	}
	
    bool empty()const
	{
		//判断栈是否为空
		return cur == 0;
	}
    
    void clear(){cur = 0;}
    bool full()const
	{
		//判断栈是否满
		return cur == len;
	}
};



int main()
{
	Stack <int,6> si;
	Stack <const char*,7> str;
	si.push(10);si.push(20);si.push(30);si.push(50);si.push(60);si.push(70);
	print(si,',');
	char buf[100];
	for(;;){
		cin >> buf;
		if(strcmp(buf,"end") == 0) break;
		str.push(buf);
	}
	print(str,',');
	return 0;
}
