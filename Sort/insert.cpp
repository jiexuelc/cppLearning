/*************************************************************************
	> File Name: insert.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Tue 05 Jun 2018 06:34:39 PM CST
	> Description: 插入排序算法(像扑克牌一样)
 ************************************************************************/

#include<algorithm>
using std::swap;

//void insert_sort(int* a,int n)
void sort(int* a,int n)
{
	int j;
	for(int i = 1; i < n; i++){//从第二个值开始，循环n-1次
		int temp = a[i];//暂存要插入的值
		//从右向左找，每遇到一个比插入值大的数据，就将其向右移动一个位置，直到遇到左边第一个不大于插入值的数据停下，或者左边没有位置停下
		for(j=i-1;j>=0 || temp < a[j];j--){
			a[j+1] = a[j];
		}
		a[j+1] = temp;//在停下来的位置插入该数据
	}
}
