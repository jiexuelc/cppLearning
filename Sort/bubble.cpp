/*************************************************************************
	> File Name: bubble.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Tue 05 Jun 2018 04:47:00 PM CST
	> Description: 冒泡法排序算法
 ************************************************************************/
#include<algorithm>
using std::swap;


/*void sort(int* a,int n)
{
	bool changed;//交换标志
	do{
		changed = false;//置位标志
		for(int i = 1; i< n; i++){
			int j = i-1;
			if(a[i] < a[j]){
				swap(a[i],a[j]);//交换函数，库里自带
				changed = true;
			}
		}
		--n;//每一轮都会将前面最大的数移动到末端，所以后面没有必要再进行比较
	}while(changed);
}*/

//调试结果显示，进行一次空间开辟和减法运算与进行两次减法运算相比，有更大的时间和空间复杂度

//void bubble_sort(int* a,int n)
void sort(int* a,int n)
{
	bool changed;//交换标志
	do{
		changed = false;//置位标志
		for(int i = 1; i< n; i++){
			if(a[i] < a[i-1]){
				swap(a[i],a[i-1]);//交换函数，库里自带
				changed = true;
			}
		}
		--n;//每一轮都会将前面最大的数移动到末端，所以后面没有必要再进行比较
	}while(changed);
}