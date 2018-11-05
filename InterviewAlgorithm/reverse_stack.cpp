/*************************************************************************
 * > File Name: reverse_stack.cpp                                                     *
 * > Author: jiexue
 * > Mail: jiexuelc@163.com
 * > Created Time: Mon 08 Oct 2018 08:26:52 PM CST
 * > Description: 将一个栈依次压入1、2、3、4、5，从栈底到栈顶依次为5、4、3、2、1
                  用递归函数实现将这个栈转置，不能用其他数据结构。最终栈顶到栈底为1、2、3、4、5
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

/*
 * 获取栈底元素并删除，且除栈底之外的其他数据保持不变
 * 例如：原始数据:栈底--->栈顶: 3 2 1
 *      处理结果:1.栈底--->栈顶: 2 1
 *              2.返回处理结果3
 */
int getAndRemoveLastElement(stack<int>& s)
{
    int result = s.top();   //返回栈顶的元素，但不删除该元素
    s.pop();    //删除栈顶元素但不返回其值
    if(s.empty()) {
        return result;
    } else {
        int last = getAndRemoveLastElement(s);
        s.push(result);
        return last;
    }
}

/*
 * 将栈元素反转
 * 例如：原始数据:栈底--->栈顶: 3 2 1
 *      处理结果:栈底--->栈顶: 1 2 3
 */
void reverse(stack<int>& s)
{
    if(s.empty())
    {
        return;
    }
    int temp = getAndRemoveLastElement(s);
    reverse(s);
    s.push(temp);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    reverse(s);
    
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}