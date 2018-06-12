/*************************************************************************
	> File Name: special_containers.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Tue 12 Jun 2018 05:01:13 PM CST
	> Description: 特殊容器
 ************************************************************************/
/*
 * 特殊容器：stack、queue、priority-queue
 * 1.操作.push(element)，.pop()，.empty()，.size()
 * 	stack:.top()
 * 	queue:.front()，.back()
 * 	priority_queue:.top()
 * 2.没有迭代器 
 */

#include<iostream>
#include <queue>
using namespace std;


int main()
{
	priority_queue<int> pq;
	pq.push(30);pq.push(50);pq.push(60);pq.push(20);
	pq.push(90);pq.push(80);pq.push(95);pq.push(65);
	while(! pq.empty()){
		cout << pq.top() << ' ';
		pq.pop();//并不负责带回数据，只是弹出
	}
	
	return 0;
}
