/*************************************************************************
	> File Name: ArrayPointer.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Sat 15 Sep 2018 09:24:25 PM CST
	> Description: 对于一个数组，取 &a[0] 地址和取 &a 地址表示含义的不同
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int ai[5] = {1,2,3,4,5};
    int *ptr = (int*)(&ai + 1); //这里&ai地址得到的是整个数组的地址，在整个数组地址上加1偏移的是整个数组地址大小
    cout << " *(ai + 1): " << *(ai + 1) << endl;    //这里结果为2
    cout << "*(ptr - 1): " << *(ptr - 1) << endl;   //这里结果为5
    
    return 0;
}

