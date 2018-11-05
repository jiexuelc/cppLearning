/*************************************************************************
	> File Name: Const.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Fri 28 Sep 2018 12:39:56 PM CST
	> Description: const限定
            1.g++编译运行后面使用n的值的地方会直接用100代替
            2.
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    const int n = 100;    //g++编译运行后面使用n的值的地方会直接用100代替
    volatile const int m = 200;   //m随时可能改变，每次从内存重取
    int* p = (int*)&n;  //可以看出强制转换的风险，后面通过指针会间接修改掉n的值
    *p = 123;
    cout << *p << endl;
    p = (int*)&m;
    *p = 456;
    printf("%d, %d\n", n, m);
    
    return 0;
}