/*************************************************************************
	> File Name: stack_template.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Wed 06 Jun 2018 09:39:30 PM CST
	> Description: 栈模板的创建与使用
 ************************************************************************/

#include<iostream>
#include "print.h"
using namespace std;

template <typename T>
class Stack{
    T str[5];
    int cur;
public:
    Stack():cur(0){}
    void push(const T& d)throw(const char*);
    T& pop()throw(const char*);
    const T& top()const;
    bool empty()const;
    void clear(){cur = 0;}
    bool full()const;
};

template <typename T>
void Stack<T>::push(const T& d)throw(const char*)
{
    //入栈操作
    if(full())throw "full";
    str[cur++] = d;
}

template <typename T>
bool Stack<T>::full()const
{
    //判断栈是否满
    return cur == 5;
}

template <typename T>
bool Stack<T>::empty()const
{
    //判断栈是否为空
    return cur == 0;
}

template <typename T>
T& Stack<T>::pop()throw(const char*)
{
    //出栈操作
    if(empty())throw "empty";
    return str[--cur];
}

template <typename T>
const T& Stack<T>::top()const
{
    //获得栈顶元素
    return str[cur-1];
}

int main()
{
	Stack <int> si;
	Stack <char> sc;
	sc.push('a');sc.push('b');sc.push('c');sc.push('d');
	si.push(10);si.push(20);si.push(30);si.push(50);
	while(!sc.empty())
		cout << sc.pop() << ' ';
	cout << endl;
	print(si,',');
	return 0;
}
