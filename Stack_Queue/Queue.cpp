/*************************************************************************
	> File Name: Queue.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Thu 31 May 2018 01:44:51 PM CST
	> Description: 数组实现队列：队首队尾位置向增长方向循环变化、刚开始队首队尾同在0位置
 ************************************************************************/

#include<iostream>
using namespace std;
typedef string T;

class Queue{
    T str[5];//队列最大长度
	int cur;//队首位置
	int queueSize;//有效元素个数
public:
	Queue():cur(0),queueSize(0){}
    Queue& push(const T& d)throw(const char*);
    T& pop()throw(const char*);
    const T& front() const;
	const T& back()const;
    bool empty()const{return queueSize == 0;};
    void clear();
    bool full(){return queueSize == 5;}
};

Queue& Queue::push(const T& d)throw(const char*)
{
	if(full()) throw "full";
	str[(cur+queueSize++)%5] = d;//循环从队尾入队
	return *this;
}

T& Queue::pop()throw(const char*)
{
	if(empty())throw "empty";
	queueSize--;//出队时队列长度减一
	return str[cur++%5];//队首位置向后移动一个
}

const T& Queue::front() const
{
	return str[cur%5];
}

const T& Queue::back()const
{
	return str[(cur+queueSize-1)%5];
}

void Queue::clear()
{
	cur = 0;
	queueSize = 0;
}

int main()
{
	Queue q;
	try{
        q.push("lichao");
        q.push("liranlong");
        q.push("lichun");
		cout << q.pop() << endl;
		cout << q.pop() << endl;
        q.push("limao");
        q.push("lilin");
        q.push("wanglin");
		q.push("lichao");
		q.push("wanglin");
    }
    catch(const char *e){
        cout << "异常：" << e <<endl;
    }
    cout << "队首元素：" << q.front() <<endl;
	cout << "队尾元素：" << q.back() <<endl;
    try{
        while(!q.empty())
            cout << q.pop() <<endl;
        cout << q.pop() << endl;
    }
    catch(const char *e){
        cout << "异常：" << e <<endl;
    }
    return 0;
}
