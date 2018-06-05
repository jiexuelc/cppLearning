/*************************************************************************
	> File Name: select.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Tue 05 Jun 2018 07:23:16 PM CST
	> Description: 选择排序、依次找出右边部分最小值所在位置和左边交换
 ************************************************************************/

#include<algorithm>
using std::swap;
/*
//void select_sort(int* a,int n)
void sort(int* a,int n)
{
	int temp;
	for(int i = 0; i < n-1; i++){//从第二个值开始，循环n-1次
		int min = i;
		for(int j = i+1; j<n; j++)
			if(a[j] < a[min])
				min = j;
			
		swap(a[min],a[i]);
	}
}*/

//本例实测下面的代码时间复杂度更低
//void select_sort(int* a,int n)
void sort(int* a,int n)
{
	int temp, pos, min;
	for(int i = 0; i < n-1; i++){//从第二个值开始，循环n-1次
		min = a[i];
		for(int j = i+1; j<n; j++)
			if(a[j] < min){
				min = a[j];
				pos = j;
			}
		a[pos] = a[i];
		a[i] = min;
	}
}