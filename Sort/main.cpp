/*************************************************************************
	> File Name: main.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Tue 05 Jun 2018 04:55:55 PM CST
	> Description: 计算排序算法的时间复杂度
 ************************************************************************/

#include<iostream>
#include<ctime>
using namespace std;
void sort(int* a, int n);

int main()
{
	const int N = 32767;
	int ai[N];
	for(int i = 0; i < N; i++){
		ai[i] = N-i;
	}
	for(int i = 0; i < 16; i++){
		cout << ai[i] << ' ';
	}
	cout << endl;
	clock_t t1 = clock();
	sort(ai,N);
	clock_t t2 = clock();
	cout << double(t2-t1) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
	for(int i = 0; i < 16; i++){
		cout << ai[i] << ' ';
	}
	cout << endl;
	return 0;
}