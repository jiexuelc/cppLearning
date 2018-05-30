/*************************************************************************
	> File Name: Stack.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Wed 30 May 2018 08:53:07 PM CST
	> Description: 利用数组模拟栈操作
 ************************************************************************/

#include<iostream>
using namespace std;
typedef string T;

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

void Stack::push(const T& d)throw(const char*)
{
    //入栈操作
    if(full())throw "full";
    str[cur++] = d;
}

bool Stack::full()const
{
    //判断栈是否满
    return cur == 5;
}

bool Stack::empty()const
{
    //判断栈是否为空
    return cur == 0;
}

T& Stack::pop()throw(const char*)
{
    //出栈操作
    if(empty())throw "empty";
    return str[--cur];
}

const T& Stack::top()const
{
    //获得栈顶元素
    return str[cur-1];
}
int main()
{
    Stack s;
    try{
        s.push("liranlong");
        s.push("lichao");
        s.push("lichun");
        s.push("limao");
        s.push("lilin");
        s.push("wanglin");
    }
    catch(const char *e){
        cout << "异常：" << e <<endl;
    }
    cout << "栈顶元素：" << s.top() <<endl;
    try{
        while(!s.empty())
            cout << s.pop() <<endl;
        cout << s.pop() << endl;
    }
    catch(const char *e){
        cout << "异常：" << e <<endl;
    }
    return 0;
}
